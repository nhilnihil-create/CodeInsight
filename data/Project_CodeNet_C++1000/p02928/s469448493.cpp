#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
int main(void){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<ll> b(n,0),c(n,0);
    rep(i,n){
        for(int j=0;j<i;j++){
            if(a[i]>a[j])b[i]++;
        }
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j])c[i]++;
        }
    }
    ll res=0;
    rep(i,n){
        ll buf=(c[i]*k%mod+(b[i]+c[i])*((k-1)*k/2%mod))%mod;
        res=(res+buf)%mod;
        //cout<<res<<endl;
    }
    cout<<res<<endl;
}
