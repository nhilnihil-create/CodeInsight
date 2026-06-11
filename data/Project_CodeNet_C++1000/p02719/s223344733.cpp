#include<iostream>
#include<vector>//可変長配列
#include<algorithm>//sort,二分探索,など
#include<map>//map(辞書)

using namespace std;

int main(void){
    long int N, K;
    cin >> N >> K;
    if(N > K) N %= K;
    while(abs(N-K) < N){
        N = abs(N-K);
        // cout << N << endl;
    }
    cout << N << endl;
    return 0;
}