#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m,v,p;cin>>n>>m>>v>>p;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.rbegin(),a.rend());
    
    auto ok=[&](int i){
        if(i<p)return true;
        ll t= a[i]+m;
        ll f=0;
        for(int j=p-1;j<n;j++){
            if(i==j)continue;
            if(t<a[j])return false;
            f+=min(t-a[j],m);
        }
        return f>=m*(v-p);
    };
    int left=-1,right=n;
    while(right-left>1){
        int mid=(right+left)/2;
        if(ok(mid))left=mid;
        else right=mid;
    }
    cout<<right<<endl;
}
