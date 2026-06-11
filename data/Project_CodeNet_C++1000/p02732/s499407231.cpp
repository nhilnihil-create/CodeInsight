#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

ll n;
vector<ll> a(200100);
map<ll,ll> dict;

int main(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        dict[a[i]]++;
    }
    ll sum=0;
    rep(i,0,dict.size()) sum+=dict[i]*(dict[i]-1)/2;

    vector<ll> ans(n);
    rep(i,0,n){
        ans[i]=sum-(dict[a[i]]-1);
    }
    rep(i,0,n) cout<<ans[i]<<"\n";
    return 0;
}