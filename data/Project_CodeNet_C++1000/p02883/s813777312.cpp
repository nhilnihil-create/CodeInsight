#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,k;cin>>n>>k;
    vector<ll> a(n),f(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>f[i];
    sort(a.begin(),a.end());
    sort(f.rbegin(),f.rend());
    ll left=-1,right=1e18;
    while(right-left>1){
        ll mid=(right+left)/2;
        ll tot=0;
        rep(i,n){
            ll buf=a[i]*f[i];
            buf-=mid;
            tot+=max((ll)0,(buf+f[i]-1)/f[i]);
        }
        if(tot>k)left=mid;
        else right=mid;
    }
    cout<<right<<endl;
}
