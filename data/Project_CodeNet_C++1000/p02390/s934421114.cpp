#include<iostream>
int main() {
	int S;
	std::cin >> S;
	int h = S / 3600;
	int a = S % 3600;
	int m = a / 60;
	int s = a % 60;
	std::cout << h << ":" << m << ":" << s << std::endl;
	return 0;
}
    