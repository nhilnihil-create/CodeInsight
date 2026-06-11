#include<iostream>

int main(void){
    int h, n, a;
    std::cin >> h >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
	std::cin >> a;
	sum += a;
    }
    if(h <= sum) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
    return 0;
}

