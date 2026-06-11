#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    const ll mod=1e9+7;
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    rep(i,n)cin>>a[i];
    ll ans=1;
    b[0]=3;
    rep(i,n){
        ans*=b[a[i]];
        ans%=mod;
        b[a[i]]--; b[a[i]+1]++;
    }
    cout<<ans%mod<<endl;
}
