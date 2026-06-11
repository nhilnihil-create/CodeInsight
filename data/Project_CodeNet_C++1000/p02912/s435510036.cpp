#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using pll = pair<ll,ll>;
const ll INF64 = 1LL << 60;
const int INF = (1 << 29);

int main(){
    int n,m; cin >> n >> m;
    priority_queue<ll> que;
    rep(i,n){
        ll a; cin >> a;
        que.push(a);
    }

    rep(_,m){
        ll x = que.top(); que.pop();
        x /= 2;
        que.push(x);
    }

    ll ans = 0;
    while(!que.empty()){
        ll x = que.top(); que.pop();
        ans += x;
    }

    cout << ans << endl;
}