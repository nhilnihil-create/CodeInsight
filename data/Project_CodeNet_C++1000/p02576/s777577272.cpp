#include<iostream>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int stock = 0;
	int time = 0;
	std::cin >> a >> b >> c;
	for (int i = 0; i < 10000;i++) {
		if (a>stock) {
			time += c;
			stock += b;
			
		}
		else {
			break;
		}
	}
	std::cout << time;
}