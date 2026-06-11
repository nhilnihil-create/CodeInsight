#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;
ll k;
int a[200010],f[200010];

bool calc(ll mid, ll cnt=k){
    rep(i,n){
        cnt-=max(0LL,a[i]-(mid/f[i]));
    }
    return cnt>=0;
}

int main(){
    cin>>n>>k;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>f[i];
    sort(a,a+n);
    sort(f,f+n);
    reverse(f,f+n);
    ll l=-1,r=1e12+1;
    while(r-l>1){
        ll mid=(l+r)/2;
        if(calc(mid))r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}