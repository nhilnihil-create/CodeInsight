#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    ll ans=0;
    ll n=s.size();
    vector<ll>a(n+1,0);
    for(ll i=0;i<n;i++){
        if(s[i]=='<'){
            a[i+1]=max(a[i+1],a[i]+1);
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='>'){
            a[i]=max(a[i],a[i+1]+1);
        }
    }
    for(ll i=0;i<n+1;i++){
        ans+=a[i];
    }
    cout << endl;
    cout << ans << endl;
}