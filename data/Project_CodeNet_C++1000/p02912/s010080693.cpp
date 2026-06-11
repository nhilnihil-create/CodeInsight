#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> p;

int main(){
    ll n,m; cin >> n >> m;
    priority_queue<ll> que;
    for(ll i=0; i<n; ++i){
        ll a; cin >> a; que.push(a);
    }
    for(ll i=0; i<m; ++i){
        ll t = que.top(); que.pop();
        t /= 2;
        que.push(t);
    }
    ll sum = 0;
    while(!que.empty()){
        sum += que.top(); que.pop();
    }
    cout << sum << endl;
    return 0;
}