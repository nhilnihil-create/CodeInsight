#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int A,B,M;
cin>>A>>B>>M;
vector<int> a(A),b(B),x(M),y(M),c(M);
rep(i,A)cin>>a[i];
rep(i,B)cin>>b[i];
rep(i,M){
    cin>>x[i]>>y[i]>>c[i];
    x[i]--,y[i]--;
}
vector<ll> cost;
rep(i,M){
    cost.pb(a[x[i]]+b[y[i]]-c[i]);
}

sort(a.begin(),a.end());
sort(b.begin(),b.end());
sort(cost.begin(),cost.end());
if(a[0]+b[0]<cost[0]){
    cout<<a[0]+b[0]<<endl;
}
else{
    cout<<cost[0]<<endl;
}

return 0;
}