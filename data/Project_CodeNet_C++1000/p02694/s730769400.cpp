#include<iostream>

int main(void){
    long long x;
    std::cin >> x;
    long long cur = 100;
    long long ans = 0;

    while(true){
	ans++;
	cur += cur / 100;
	if(cur >= x){
	    break;
	}
    }
    std::cout << ans << std::endl;


    return 0;
}

