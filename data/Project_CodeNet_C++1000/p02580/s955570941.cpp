// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
set<int> h[303030], w[303030]; // 爆破対象: 行方向, 列方向.

int main() {
    
    // 1. 入力情報取得.
    int H, W, M;
    int mhCnt = 0, mwCnt = 0; // 爆破対象の最大数(行方向, 列方向).
    scanf("%d %d %d", &H, &W, &M);
    rep(i, M){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        h[a].insert(b);
        w[b].insert(a);
        mhCnt = max(mhCnt, (int)h[a].size());
        mwCnt = max(mwCnt, (int)w[b].size());
    }
    
    // 2. 最大数を持つ行, 列 を 集約.
    set<int> mhSet, mwSet;
    rep(i, 303030){
        if(mhCnt == h[i].size()) mhSet.insert(i); // 行番号.
        if(mwCnt == w[i].size()) mwSet.insert(i); // 列番号.
    }
    
    // 3. 最大数を計算.
    int ans = mhCnt + mwCnt - 1;
    for(auto &p : mhSet){
        bool ok = false;
        for(auto &q : mwSet){
            // 列方向の最大数に該当する 列番号 q で, 行方向の最大数を取る 行番号 p を 含まない
            // ものが見つかった場合は, 終了.
            if(w[q].count(p) == 0){
                ans++;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    
    // 4. 出力.
    printf("%d\n", ans);
    return 0;
    
}