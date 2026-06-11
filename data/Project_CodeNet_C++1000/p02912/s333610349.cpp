#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

ll mmod[100010][31];

int main(){
    ll n, m;
    cin >> n >> m;
    priority_queue<ll> que;
    rep(i, n){
        ll a; cin >> a;
        que.push(a);
    }
    rep(i, m){
        ll tmp = que.top(); que.pop();
        que.push(tmp/2);
    }
    ll ans = 0;
    while(!que.empty()){
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}