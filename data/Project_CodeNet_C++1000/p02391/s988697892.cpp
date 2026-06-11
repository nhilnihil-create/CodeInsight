#include <iostream>
#include <stdio.h>
int main(){
	int a,b;
	std::cin >> a;
	std::cin >> b;
	if(a!=b){
		if(a>b)
	std::cout << "a" <<" "<< ">" <<" "<< "b" << std::endl;
		else
	std::cout << "a" <<" "<< "<" <<" "<< "b" << std::endl;
	}
	else
	std::cout << "a" <<" "<< "==" <<" "<< "b" << std::endl;
	return 0;
}