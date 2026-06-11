#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans=0;
    for(ll i=0;i<1000;i++){
        ll c[3]={i/100,(i/10)%10,i%10};
        ll f=0;
        for(ll j=0;j<n;j++){
            if(s[j]==('0'+c[f])) f++;
            if(f==3) break;
        }
        if(f==3)ans++;
    }
    cout << ans << endl;
}