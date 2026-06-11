#include<string.h>
#include<iostream>

int main() {
	std::string we;
	std::cin >> we;
	std::string::iterator it;
	int ren=0;
	it = we.begin();

	if (*it == 'R' && *(it + 1) == 'R' && *(it + 2) == 'R') { ren = 3; }
	else if (*it == 'R' && *(it + 1) == 'R' && *(it + 2) == 'S') { ren = 2; }
	else if (*it == 'S' && *(it + 1) == 'R' && *(it + 2) == 'R') { ren = 2; }
	else if (*it == 'S' && *(it + 1) == 'S' && *(it + 2) == 'R') { ren = 1; }
	else if (*it == 'S' && *(it + 1) == 'R' && *(it + 2) == 'S') { ren = 1; }
	else if (*it == 'S' && *(it + 1) == 'S' && *(it + 2) == 'S') { ren = 0; }
	else if (*it == 'R' && *(it + 1) == 'S') { ren = 1; }
	std::cout << ren << std::endl;
}