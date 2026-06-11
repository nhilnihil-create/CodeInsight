#include <bits/stdc++.h>
using namespace std;

int main(){
    // 1. 入力情報取得.
    int N, K;
    scanf("%d %d", &N, &K);
    
    // 2. ボールの個数の差としてあり得る最大値.
    // K = 1 の 場合, 最大: N,         最小: N
    // K > 1 の 場合, 最大: N + 1 - K, 最小: 1
    int maxB = 0, minB = 0;
    if(K == 1) maxB = minB = N;
    else       maxB = N + 1 - K, minB = 1;
    
    // 3. 出力.
    printf("%d\n", maxB - minB);
    return 0;
}