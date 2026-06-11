#include <iostream>
int main(int argc, char** argv){
	int n;
	std::cin >> n;
	int c = 0, f = 0;
	for(int i=0; i<n; i++){
		int a,b;
		std::cin >> a >> b;
		if(a == b) c++;
		else c = 0;
		if(c == 3) f = 1;
	}
	std::cout << (f ? "Yes":"No") << "\n";
}