#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<char>s(n);
    ll cnt_r=0,cnt_g=0,cnt_b=0;
    for(ll i=0;i<n;i++){
        cin >> s[i];
        if(s[i]=='R') cnt_r++;
        if(s[i]=='G') cnt_g++;
        if(s[i]=='B') cnt_b++;
    }
    ll ans=cnt_r*cnt_g*cnt_b;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll k=2*j-i;
            if(k>=n) continue;
            if(s[i]!=s[j]&&s[j]!=s[k]&&s[k]!=s[i]){
                ans--;
            }
        }
    }
    cout << ans << endl;
}