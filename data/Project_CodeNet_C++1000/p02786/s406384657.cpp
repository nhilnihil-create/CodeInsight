#include <iostream>
#include <cmath>

int main(void){
    int N=0;
    long long H, ans=0;
    std::cin >> H;

    while (true){
        H /= 2LL;
        if (H == 0) break;
        ++N;
    }

    for (int i=0; i<=N; i++){
        ans += pow(2, i);
    }

    std::cout << ans << std::endl;

    return 0;
}
