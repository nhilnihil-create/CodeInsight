#include <iostream>
#include <string>
#include <cstdlib>

int decode( std::string str )
{
	int s = 0;
	for ( int i = 0; i < str.size(); ++i ) {
		int k = 1;
		if ( str[i] == 'm' || str[i] == 'c' || str[i] == 'x' || str[i] == 'i' ) {
			if ( i != 0 && isdigit(str[i-1]) == true ) {
				k = str[i-1] - '0';
			}
			switch(str[i]) { 
				case 'm':
					s += k * 1000;
					break;
				case 'c':
					s += k * 100;
					break;
				case 'x':
					s += k * 10;
					break;
				case 'i':
					s += k;
					break;
			}
		}
	}
	return s;
}

std::string encode( int a ) {
	std::string str = "";
	char m[5] = "ixcm";

	for ( int i = 0; i < 4; ++i ) {
		int c = a % 10;
		switch(c) {
			case 0:
				break;
			case 1:
				str = m[i] + str;
				break;
			default:
				str = std::to_string(c) + m[i] + str;
				break;
		}
		a /= 10;
	}

	return str;
}

int main()
{
	int n;

	std::cin >> n;

	for ( int i = 0; i < n; ++i ) {
		std::string buf;
		std::cin >> buf;
		int a = decode(buf);
		std::cin >> buf;
		int b = decode(buf);

		int c = a + b;

		std::cout << encode(c) << std::endl;
	}
	return 0;
}