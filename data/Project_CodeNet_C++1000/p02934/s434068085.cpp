#include<iostream>
#include<iomanip>

int main(void){
    int n, a;
    std::cin >> n;
    double ans;
    double tmp = 0;
    for(int i = 0; i < n; i++){
        std::cin >> a;
        tmp += 1.0 / a;
    }
    ans = 1/ tmp;
    std::cout << std::fixed << std::setprecision(15) << ans << std::endl;
    return 0;
}