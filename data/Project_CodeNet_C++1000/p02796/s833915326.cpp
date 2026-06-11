#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>>x(n);
    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        x[i]={a+b,a-b};
    }
    ll ans=0;
    ll cur=-MOD;
    sort(x.begin(),x.end());
    for(ll i=0;i<n;i++){
        if(cur<=x[i].second){
            ans++;
            cur=x[i].first;
        }
    }
    cout << ans << endl;
}
