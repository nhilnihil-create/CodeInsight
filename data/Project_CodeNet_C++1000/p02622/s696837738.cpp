#include <iostream>
#include <string>

int main() {
	std::string s,t;
  	std::cin >> s >> t;
  	unsigned int i = s.length(), c = 0;
  	for ( unsigned int l = 0; l < i; l++ )
		if ( s[l] != t[l] )
          	c++;
  	std::cout << c << std::endl;
  	return 0;
}

