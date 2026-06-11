#include<iostream>

long long calc(int n){

	if (n == 1)return 1;

	return n*calc(n - 1);

}

int main(){

	int n;
	std::cin >> n;

	std::cout << calc(n) << std::endl;

	return 0;
}