#include<iostream>
#include<thread>// �����
#include<chrono>

// ���������������
// std::cout - non thread-  (����������� �.� ������ ����� ���������)
void work(int x, int y) {
	std::cout << "Work started\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "Work thread: " << std::this_thread::get_id() <<'\n';
	std::cout << "Work ended!\n";
}
 
int main() {
	//work();
	std::cout << "Main thred " << std::this_thread::get_id() << '\n';
	//std::thread t1(work);
	std::thread t1([](int x, int y){
	std::cout << x << ' ' << y << ' \n';
	std::cout << "Work started\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "Work thread: " << std::this_thread::get_id() << '\n';
	std::cout << "Work ended!\n";
	},5,6);
	std::thread t2(work, 3, 2);
	std::cout << "hello!\n";
	// race condition - "�����"

	t1.join();
	t2.join();
	//�����������(Parallelism) � ��������������(Concurrency)

	return 0;
}