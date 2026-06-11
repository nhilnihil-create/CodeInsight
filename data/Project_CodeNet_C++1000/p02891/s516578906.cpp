#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s; int k;
    cin>>s>>k;
    int n=s.size();
    ll ans=0,cnt=1;
    set<char>se;
    rep(i,n)se.insert(s[i]);
    if(se.size()==1){cout<<(ll)n*k/2<<endl; return 0;}
    rep(i,n-1){
        if(s[i]==s[i+1])cnt++;
        else{ans+=cnt/2; cnt=1;}
    }
    ans+=cnt/2;
    ll cnt2=1,ans2=0;
    s+=s;
    n=s.size();
    rep(i,n-1){
        if(s[i]==s[i+1])cnt2++;
        else{ans2+=cnt2/2; cnt2=1;}
    }
    ans2+=cnt2/2;
    ll x=ans2-ans;
    cout<<ans+x*(k-1)<<endl;
}
