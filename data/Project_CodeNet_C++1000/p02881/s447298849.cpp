#include<iostream>
#include<cmath>

const static long long INF = 1e13;
int main(void){
    long long n;
    std::cin >> n;
    long long ub = std::sqrt(n);
    long long ans = INF;
    for(int i = 1; i <= ub; i++){
        if(n % i == 0){
            long long tmp = (i - 1) + (n / i - 1);
            ans = std::min(ans, tmp);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}