#define MAX 10000
#include<iostream>

int main(){
	int D, T, S;
	std::cin >> D >> T >> S;
	if(S*T>=D)
		std::cout << "Yes";
	else
		std::cout << "No";

	std::cin.get();
}
