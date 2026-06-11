#include <iostream>
 
int main() {
	int x, y;
  
  	scanf("%d", &x);
  	scanf("%d", &y);
  	
  	//std::string s = std::to_string( a );
  	std::string a;
  	std::string b;
  
  	for (int i = 0; i < y; i++) {
    	a += std::to_string(x);
    }
  
  	for (int i = 0; i < x; i++) {
    	b += std::to_string(y);
    }
  	
  	if (a < b) {
      std::cout << a << std::endl;
      return 0;
    
    }
  	std::cout << b << std::endl;
  	return 0;
}