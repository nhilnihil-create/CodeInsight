#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,less<pair<ll,ll>>> que;
    ll count = 0;
    rep(i,n){ if(b[i] > a[i]) que.push(make_pair(b[i],i)); else if(b[i] == a[i]) count++; }
  
    ll ans = 0;
    while(!que.empty()){
      	pair<ll,ll> p = que.top(); que.pop();
        ll num, id; tie(num,id) = p;
        ll div = b[(id+1)%n] + b[(id+n-1)%n];
        ll k = (num - a[id]) / div;
        ans += k; if(k == 0){ cout << -1 << endl; return 0; }
        b[id] -= k * div; 
        if(b[id] > a[id]) que.push(make_pair(b[id],id));
        else if( b[id] == a[id]) count++;
    }
    cout << (count == n ? ans : -1) << endl;
    return 0;
}