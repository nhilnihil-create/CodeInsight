#include<iostream>

int main(void){
    long long h, ans = 0, cn = 1;
    std::cin >> h;
    while(h != 0){
	ans += cn;
	h /= 2;
	cn *= 2;
    }
    std::cout << ans << std::endl;
    return 0;
}

