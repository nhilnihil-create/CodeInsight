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
int n;
cin>>n;
vector<ll>a(n),s(n,0),t(n,0);

rep(i,n){
    cin>>a[i];
}
s[0]=a[0];
t[n-1]=a[n-1];
rep(i,n-1){
    int idx_s=i;
    int idx_t=n-1-i;
    s[idx_s+1]=s[idx_s]+a[idx_s+1];
    t[idx_t-1]=t[idx_t]+a[idx_t-1];
}
ll min_cost=INF;
rep(i,n-1){
    min_cost=min(min_cost,abs(s[i]-t[i+1]));
}
cout<<min_cost<<endl;
return 0;
}