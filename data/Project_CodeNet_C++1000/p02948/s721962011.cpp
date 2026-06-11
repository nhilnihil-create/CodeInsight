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
    ll n, m;
    cin >> n >> m;

    // reward[i] : i+1日後にもらえる報酬のベクトル
    vector<vector<ll>> reward(100010);
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        reward[a-1].push_back(b);
    }

    // 未来から逆算，Mまでにもらえる最大報酬のバイトをする
    priority_queue<ll> que;
    ll ans = 0;
    rep(i, m){
        for(ll r_i : reward[i])que.push(r_i);

        if(!que.empty()){
            ans += que.top();
            que.pop();
        }
    }

    cout << ans << endl;
}