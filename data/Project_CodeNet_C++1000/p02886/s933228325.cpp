#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;

int main(){
    cin>>n;
    vector<int> d(n);
    rep(i,0,n) cin>>d[i];
    ll ans=0;
    rep(i,0,n-1){
        ll num=0;
        rep(j,i+1,n) num+=d[j];
        ans+=d[i]*num;
    }
    cout<<ans<<"\n";
    return 0;
}
