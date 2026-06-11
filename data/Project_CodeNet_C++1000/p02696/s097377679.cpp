#include<iostream>

int main(void){
    long long a, b, n;
    std::cin >> a >> b >> n;
    if(b - 1 <= n){
	std::cout << (a * (b - 1)) / b - a * ((b - 1) / b) << std::endl;
    }else{
	std::cout << (a * n) / b - a * (n / b) << std::endl;
    }
    return 0;
}

