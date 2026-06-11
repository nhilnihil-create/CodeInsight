// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<LL>;
using vvl = vector<vl>;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
int P[5050], memo[5050], idx[5050], gIdx[5050];
LL C[5050];

int main(){
    
    // 1. 入力情報.
    int N;
    LL K;
    scanf("%d %lld", &N, &K);
    rep(i, N) scanf("%d", &P[i + 1]);
    rep(i, N) scanf("%lld", &C[i]);
    
    // 2. 巡回する整数ごとにグループ分け.
    vvi g;     // グループ情報.
    int n = 0; // グループ番号.
    vvl gCum;  // グループごとの累積和.
    repx(i, 1, N + 1){
        vi v;
        int cur = i;
        while(!memo[cur]){
            // 2-1. グループに追加.
            v.pb(cur);
            
            // 2-2. 訪問済みフラグ設定.
            memo[cur] = 1;
            
            // 2-3. グループ番号を設定.
            idx[cur] = n;
            
            // 2-4. 次のマス.
            cur = P[cur];
        }
        
        // 2-5. グループサイズが, 0 より大きい場合.
        int l = v.size();
        if(l){
            // グループを追加.
            g.pb(v);
            
            // グループに関する累積和, 追加.
            vl c(l * 2 + 2, 0LL);
            rep(i, l * 2 + 1) c[i + 1] = c[i] + C[v[i % l] - 1];
            gCum.pb(c);
            
            // グループ番号をインクリメント.
            n++;
        }
    }
    // for(auto &v : g){
    //     for(auto &u : v) printf("%d ", u);
    //     puts("");
    // }
    // repx(i, 1, N + 1) printf("%d ", idx[i]);
    // puts("");
    // for(auto &v : gCum){
    //     for(auto &u : v) printf("%lld ", u);
    //     puts("");
    // }
    
    // 3. 各グループごとに, ゲーム終了時のスコアとして, 有り得る最大値を計算.
    LL ans = -202020202020202020;
    repx(i, 1, N + 1){
        // 3-1. 出発点の所属グループ.
        int sg = idx[i];
        
        // 3-2. 出発点の所属グループのサイズ.
        int gSize = g[sg].size();
        
        // 3-3. 周期を計算.
        LL q = K / (LL)gSize, r = K % (LL)gSize;
        
        // 3-4. 項数 1 ～ r 個 までの累積和を全探索.
        // [gIdx[sg], gIdx[sg] + 1], ..., [gIdx[sg], gIdx[sg] + r] の r個 の 区間 を 確認.
        LL t1 = -202020202020202020;
        repx(j, 1, r + 1) t1 = max(t1, gCum[sg][gIdx[sg] + j] - gCum[sg][gIdx[sg]]);
        
        // 3-5. 1周期以上ある場合.
        LL t2 = -202020202020202020, t3 = -202020202020202020;
        if(q){
            // 1周期以下.
            // [gIdx[sg], gIdx[sg] + r + 1], ..., [gIdx[sg], gIdx[sg] + gSize] の (gSize - r)個 の 区間 も 確認.
            repx(j, r + 1, gSize + 1) t2 = max(t2, gCum[sg][gIdx[sg] + j] - gCum[sg][gIdx[sg]]);
            
            // 1周期を超える場合.
            if(gCum[sg][gSize] > 0){
                // t2 の 結果を優先しない場合.
                t3 = max(t3, t1 + q * gCum[sg][gSize]);
                
                // t2 の 結果を優先する場合.
                t3 = max(t3, t2 + (q - 1) * gCum[sg][gSize]);
            }
        }
        
        // 3-6. 出発点の所属グループにおけるインデックスをインクリメント.
        gIdx[sg]++;
        
        // 3-7. ゲーム終了時のスコアの最大値更新.
        ans = max({ans, t1, t2, t3});
    }
    
    // 4. 出力.
    printf("%lld\n", ans);
    return 0;
    
}
