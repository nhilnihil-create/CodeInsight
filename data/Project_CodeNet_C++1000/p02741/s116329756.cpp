#include <iostream>
 
int main(){
	int array[32] = {1, 1, 1, 2, 1, 2, 1,
                     5, 2, 2, 1, 5, 1, 2, 1, 
                     14, 1, 5, 1, 5, 2, 2, 1, 
                     15, 2, 2, 5, 4, 1, 4, 1, 51};
  
	int n;
	std::cin >> n;
  
  	std::cout << array[n - 1] << std::endl;
 	return 0;     
}