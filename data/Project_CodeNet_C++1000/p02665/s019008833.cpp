// 解き直し.
// https://img.atcoder.jp/nomura2020/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const int MAX = 101010;
LL A[MAX], B[MAX], ACUM[MAX];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N + 1) scanf("%lld", &A[i]);
    
    // 解説通り.
    // 2. 累積和.
    rep(i, 101010) ACUM[i + 1] = ACUM[i] + A[i];
    
    // 3. 葉でない頂点数を更新.
    // 33.txt で WA版.
    // 0
    // 2
    // -> -1 が 正解だが, 1 が 出力されたので, ロジック修正.
    // 3-1. 条件(1) を 設定.
    bool ok = true;
    B[0] = 1 - A[0];
    if(B[0] < 0) ok = false; // 33.txt 対策.
    repx(i, 1, N + 1){
        // 3-2. 条件(2), (3) から, B[i] の 候補 を 計算.
        B[i] = min(2 * B[i - 1] - A[i], ACUM[N + 1] - ACUM[i + 1]);
        
        // 3-3. 条件(2) を チェック.
        if(A[i] + B[i] < B[i - 1] || A[i] + B[i] > 2 * B[i - 1] || B[i] < 0){
            ok = false;
            break;
        }
    }
    
    // 4. 頂点数を保存.
    LL ans = 0;
    rep(i, N + 1) ans += (A[i] + B[i]);
    
    // 5. 出力.
    printf("%lld\n", ok ? ans : -1);
    return 0;
    
}