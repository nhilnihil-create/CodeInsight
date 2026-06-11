#include<iostream>

int main(void){
    long long n, d;
    std::cin >> n >> d;
    long long d2 = d * d;
    int cnt = 0;
    long long x, y;
    for(int i = 0; i < n; i++){
        std::cin >> x >> y;
        if(x * x + y * y <= d2) cnt++;
    }
    std::cout << cnt << std::endl;
    return 0;
}