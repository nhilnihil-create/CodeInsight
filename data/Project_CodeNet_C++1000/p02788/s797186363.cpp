#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

/*解説AC*/
int main(void){
    int n;
    ll d, a;
    cin>>n>>d>>a;
    vector<pair<ll, ll> > v(n);
    rep(i, n){
        ll x, h;
        cin>>x>>h;
        v[i] = make_pair(x, h);
    }
    sort(v.begin(), v.end());
    queue<pair<ll, ll> > que;
    ll ans = 0;
    ll tot = 0;
    rep(i, n){
        ll x = v[i].first;
        ll h = v[i].second;
        while(!que.empty() && que.front().first<x){
            tot -= que.front().second;
            que.pop();
        }
        h -= tot;
        if(h>0){
            ll num = (h+a-1)/a;
            ans += num;
            ll damage = num*a;
            tot += damage;
            que.emplace(x+2*d, damage);
        }
    }
    cout<<ans<<endl;
    return 0;
}