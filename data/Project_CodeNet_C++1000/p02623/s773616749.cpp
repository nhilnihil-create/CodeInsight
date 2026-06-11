#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    ll n,m,k;
    ll c,d=0;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m);
    rep(i,n) {
        cin>>c;
        d+=c;
        a[i]=d;
    }
    d=0;
    rep(i,m) {
        cin>>c;
        d+=c;
        b[i]=d;
    }
    int ans=upper_bound(b.begin(),b.end(),k)-b.begin();
    rep(i,n){
        if(a[i]<=k){
        int ho=upper_bound(b.begin(),b.end(),k-a[i])-b.begin()+i+1;
        ans=max(ans,ho);
        }else{
            break;
        }
    }
    cout<<ans<<endl;
    }