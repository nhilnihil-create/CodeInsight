#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,m;
    cin >> n >> m;
    priority_queue<ll>a;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        a.push(x);
    }
    for(ll i=0;i<m;i++){
        ll x=a.top();
        a.pop();
        x/=2;
        a.push(x);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll x=a.top();
        a.pop();
        ans+=x;
    }
    cout << ans << endl;
}