#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n,k;cin>>n>>k;
    ll a[200010],f[200010];
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>f[i];
    sort(a,a+n);
    sort(f,f+n);
    reverse(f,f+n);
    ll l=-1,r=1e12;
    while(l+1<r){
        ll c=(l+r)/2;
        ll sum=0;
        rep(i,0,n){
            sum+=max(0ll,a[i]-c/f[i]);
        }
        if(sum<=k)r=c;
        else l=c;
    }
    cout<<r<<endl;
}

    







