// 解き直し.
// ABC 143解説.
// https://img.atcoder.jp/abc143/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAX = 321123;
LL A[MAX], C[MAX], D[MAX], DCUM[MAX], KDCUM[MAX], f[MAX];

int main(){
    
    // 1. 入力情報取得.
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%lld", &A[i]), C[A[i]]++;
    for(int i = 1; i <= N; i++) D[C[i]]++;
    
    // 2. 解説通り(累積和).
    for(int i = 1; i <= N; i++) DCUM[i] = DCUM[i - 1] + D[i];
    for(int i = 1; i <= N; i++) KDCUM[i] = KDCUM[i - 1] + (LL)i * D[i];
    
    // 3. f(X) の 計算.
    // -> lower_bound を 使用する都合上, index を ずらした.
    for(int x = 0; x < N; x++){
        f[x] = KDCUM[x];
        f[x] += (LL)(x + 1) * (DCUM[N] - DCUM[x]);
        f[x] /= (x + 1);
    }
    // for(int i = 0; i <= N; i++) printf("%lld ", DCUM[i]);
    // printf("\n");
    // for(int i = 0; i <= N; i++) printf("%lld ", KDCUM[i]);
    // printf("\n");
    
    // 4. f(X) の sort.
    // -> lower_bound を 使用する都合上, 昇順sort した.
    sort(f, f + N);
    // for(int i = 0; i < N; i++) printf("%lld ", f[i]);
    // printf("\n");
    
    // 5. N個の整数を出力.
    for(int t = 1; t <= N; t++) printf("%d\n", N - (lower_bound(f, f + N, t) - f));
    return 0;
    
}