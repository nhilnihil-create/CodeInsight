#include<iostream>

int main(void){
    long long n, a, b;
    std::cin >> n >> a >> b;
    long long ans;
    long long tmp = n / (a + b);
    ans = tmp * a;
    long long tmp2 = n % (a + b);
    if(tmp2 >= a){
	std::cout << ans + a << std::endl;
    }else{
	std::cout << ans + tmp2 << std::endl;
    }

    return 0;
}

