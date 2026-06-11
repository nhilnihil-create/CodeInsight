#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    const ll mod=998244353;
    int n;
    cin>>n;
    vector<int>d(n);
    map<int,int>mp;
    rep(i,n){
        cin>>d[i];
        mp[d[i]]++;
    }
    bool ok=true;
    if(d[0]!=0)ok=false;
    if(mp[0]!=1)ok=false;
    if(ok==false){cout<<0<<endl; return 0;}
    ll ans=1;
    for(int i=1; i<n; ++i){
        ans*=mp[d[i]-1];
        ans%=mod;
    }
    cout<<ans<<endl;
}
