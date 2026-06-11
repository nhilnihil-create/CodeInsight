#include <iostream>

int main()
{
	char* s[] {"a == b", "a > b", "a < b"};
	int a, b, n;
	std::cin >> a >> b;
	n = a==b ? 0 : a>b ? 1 : 2; 
	std::cout << s[n] << '\n';
}