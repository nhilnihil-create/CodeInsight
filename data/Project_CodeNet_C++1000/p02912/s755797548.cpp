#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
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

    priority_queue<ll> que;
    rep(i, n){
        ll a;
        cin >> a;

        que.push(a);
    }

    rep(i, m){
        ll top = que.top() / 2;
        que.pop();
        que.push(top);
    }

    ll ans = 0;
    while(!que.empty()){
        ans += que.top();
        que.pop();
    }

    cout << ans << endl;
}