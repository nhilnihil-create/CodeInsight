#include<iostream>

int main(){
	int h1, h2, m1, m2, k;
	std::cin >> h1 >> m1 >> h2 >> m2 >> k;

	int term = (h2-h1)*60 + m2-m1;
	term -= k;
	std::cout << term << std::endl;
	return 0;
}