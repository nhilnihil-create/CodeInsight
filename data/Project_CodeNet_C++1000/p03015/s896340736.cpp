#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    string l;
    cin >> l;

    // dp[i][0] : i桁目で，丁度L,　dp[i][1]:L以下
    ll dp[l.size() + 1][2] = {};
    dp[0][0] = 1;

    rep(i, l.size()){
        if(l[i] == '0'){
            dp[i+1][0] = dp[i][0];// 丁度Lで０ならそのまま
            dp[i+1][1] = 3*dp[i][1];// 0:0, 0:1, 1:0の３通り
        }
        else {
            dp[i+1][0] = 2*dp[i][0];// 1:0, 0:1の２とうり
            dp[i+1][1] = 3*dp[i][1] + dp[i][0];// 0:0, 1:0, 0:1の３通りと丁度できて1->0にしたもの
        }

        dp[i+1][0] %= MOD;
        dp[i+1][1] %= MOD;
    }

    cout << (dp[l.size()][0] + dp[l.size()][1]) % MOD << endl;
}