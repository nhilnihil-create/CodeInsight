// 解き直し.
// https://img.atcoder.jp/tokiomarine2020/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int bef[202020], cur[202020];

int main(){
    
    // 1. 入力情報.
    int N, K;
    scanf("%d %d", &N, &K);
    rep(i, N) scanf("%d", &bef[i]);
    
    // 2. 各電球の光の強さを計算.
    K = min(41, K);
    rep(k, K){
        // 初期化.
        memset(cur, 0, sizeof(cur));
        
        // k回目の操作.
        rep(i, N){
            int l = max(0,     i - bef[i]);
            int r = min(N - 1, i + bef[i]);
            cur[l]++;
            if(r + 1 < N) cur[r + 1]--;
        }
        
        // 累計和から, 現在の電球の光の強さを計算.
        rep(i, N - 1) cur[i + 1] += cur[i];
        
        // 電球の光の強さを更新.
        rep(i, N)     bef[i] = cur[i];
    }
    
    // 3. 出力.
    rep(i, N){
        if(i == N - 1) printf("%d\n", cur[i]);
        else           printf("%d ",  cur[i]);
    }
    return 0;
    
}