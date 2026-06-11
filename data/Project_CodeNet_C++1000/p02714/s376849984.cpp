#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll tmp=0,r=0,g=0,b=0;
    rep(0,i,n){
        if(s[i]=='R')++r;
        else if(s[i]=='G')++g;
        else if(s[i]=='B')++b;
        rep(i+1,j,n){
            ll k=i+2*(j-i);
            if(k<n){
                if(s[i]!=s[j]&&s[j]!=s[k]&&s[i]!=s[k])++tmp;
            }
        }
    }
    cout<<r*g*b-tmp;
}