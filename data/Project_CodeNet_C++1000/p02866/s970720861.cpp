#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    const ll mod=998244353;
    int n;
    cin>>n;
    vector<int>d(n),p(n);
    rep(i,n)p[i]=0;
    rep(i,n){
        cin>>d[i];
        p[d[i]]++;
    }
    if(d[0]!=0||p[0]!=1){cout<<0<<endl; return 0;}
    ll ans=1;
    for(int i=1; i<n; ++i){
        ans*=p[d[i]-1];
        ans%=mod;
    }
    cout<<ans<<endl;
}
