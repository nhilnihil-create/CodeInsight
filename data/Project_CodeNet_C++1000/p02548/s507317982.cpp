#include <iostream>
int main(){
	int n;
	std::cin >> n;
	int c = 0;
	for(int i=1; i<n; i++){
		c += (n-1)/i;
	}
	std::cout << c << "\n";
}