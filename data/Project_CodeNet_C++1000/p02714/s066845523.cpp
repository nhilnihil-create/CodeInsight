#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    string s;
    ll r=0;
    ll g=0;
    ll b=0;
    cin>>s;
    rep(i, n){
        if(s[i]=='R') r++;
        else if(s[i]=='G') g++;
        else b++;
    }
    ll ans=r*g*b;
    for(ll i=0;i<n-2;i++){
        for(ll j=i+1;j<n-1;j++){
            if(s[j]==s[i]) continue;
            ll k=2*j-i;
            if(s[k]!=s[i]&&s[k]!=s[j]&&k<n) ans--;
        }
    }
    cout<<ans<<endl;
}