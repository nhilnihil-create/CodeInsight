#include <iostream>

int main()
{
	char c;
	char s = 'a';
	std::cin >> c;
	
	if(isupper(c)){
		s = 'A';
	}
	std::cout << s << std::endl;
	return 0;


}
