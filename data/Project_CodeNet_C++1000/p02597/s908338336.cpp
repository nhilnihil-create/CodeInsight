#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll c=0;
    rep(0,i,n){
        if(s[i]=='W')++c;
    }
    ll nc=0;
    rep(0,i,c){
        if(s[n-1-i]=='W')++nc;
    }
    cout<<c-nc;
}
