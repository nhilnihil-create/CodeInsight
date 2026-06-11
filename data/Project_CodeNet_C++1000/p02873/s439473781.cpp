#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

string s;
vector<int> a(1000010);

int main(){
    cin>>s;
    int n=s.size();
    rep(i,0,n+1) if(s[i]=='<') chmax(a[i+1],a[i]+1);
    per (i,n+1,0) if(s[i]=='>') chmax(a[i],a[i+1]+1);
    ll ans=0;
    rep(i,0,n+1) ans+=a[i];
    cout<<ans<<"\n";
    return 0;
}