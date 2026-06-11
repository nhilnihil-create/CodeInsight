#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    string s;
    cin>>s;
    string ans="";
    rep(0,i,s.length())ans+=s[i]=='?'?'D':s[i];
    cout<<ans;
}
