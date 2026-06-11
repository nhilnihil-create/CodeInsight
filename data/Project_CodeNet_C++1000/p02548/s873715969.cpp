#include <iostream>
int main(int argc, char** argv){
	int n;
	std::cin >> n;
	int c = 0, f = 0;
	for(int i=1; i<n; i++){
		c += (n-1)/i;
	}
	std::cout << c << "\n";
}