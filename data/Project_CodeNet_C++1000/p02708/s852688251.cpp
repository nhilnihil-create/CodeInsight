#include<iostream>
#include<cmath>
#include<map>
#include<vector>
using namespace std;


int main(){
    //宣言
    long long N, K, n;
    long long min, max;
    long long ans = 0;
    

    //インプット
    std::cin >> N >> K;

    for(long long i = 0; i < N+2-K ; i ++){
        //選ぶ個数のループ
        n = K + i; //選ぶ個数
        min = (0 + n-1) * n /2;
        max = (N- n + 1 + N) * n /2;
        ans = ans + max - min + 1;
    }

    std::cout << ans%1000000007;
}