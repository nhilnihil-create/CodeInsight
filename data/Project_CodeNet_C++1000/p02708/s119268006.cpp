#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
int main(void){
    ll n,k;cin>>n>>k;
    ll res=0;
    for(ll i=k;i<=n+1;i++){
        ll l=i*(i-1)/2,r=(2*n+1-i)*i/2;
        ll buf=r-l+1;
        res+=buf;
        res%=mod;
    }
    cout<<res<<endl;
}