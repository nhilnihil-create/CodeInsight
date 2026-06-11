#include<iostream>

int main(void){
	int S, h, m, s;
	
	std::cin >> S;
	h = S / 3600;
	S %= 3600;
	m = S / 60;
	S %= 60;
	s = S;
	std::cout << h << ":" << m << ":" << s <<  std::endl;
	
	return 0;
}