// C++(GCC 9.2.1)
// 解き直し.
// https://img.atcoder.jp/abc173/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    LL N, u, v, uv = 0;
    scanf("%lld", &N);
    rep(i, (int)(N - 1)){
        scanf("%lld %lld", &u, &v);
        
        // 大小関係を考慮.
        if(u > v) swap(u, v);
        
        // 辺の出現数をカウント.
        // 辺 uv は, u * (N - v + 1)回分, 頂点集合 S に含まれるはず.
        uv += u * (N - v + 1);
    }
    
    // 2. 部分グラフの連結成分の個数の総和.
    // -> 頂点集合 S におけるすべての頂点の出現数の総和は, 
    // 1, 4, 10, 20, 35, 56, ... と 増加するので, N * (N + 1) * (N + 2) / 6 で 計算されるはず.
    LL ans = N * (N + 1) * (N + 2) / 6 - uv;
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;

}