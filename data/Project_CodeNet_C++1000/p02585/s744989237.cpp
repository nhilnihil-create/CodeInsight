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
    ll n, k;
    cin >> n >> k;

    ll p[n], c[n];
    rep(i, n){
        cin >> p[i];
        p[i]--;
    }
    rep(i, n)cin >> c[i];

    ll ans = -LINF;
    rep(i, n){
        ll loop_cnt = 0;
        ll loop_sum = 0;
        ll pos = i;
    
        //ループを見つける
        while(true){
            loop_cnt++;
            loop_sum += c[pos];

            pos = p[pos];
            if(pos == i)break;
        }

        ll cnt = 0;
        ll score = 0;
        while(true){
            cnt++;
            score += c[pos];

            if(cnt > k)break;

            ll num_loop = (k - cnt) / loop_cnt;
            ans = max(ans, score + max(0ll, loop_sum)*num_loop);

            pos = p[pos];
            if(pos == i)break;
         }
    }

    cout << ans << endl;
}