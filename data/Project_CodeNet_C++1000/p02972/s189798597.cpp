#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
ll n;
vector<int> a(2e5+10);
vector<int> b(2e5+10,-1);
int res=0;
int dfs(int i){
    if(b[i]!=-1)return b[i];
    ll buf=0;
    for(int j=2;i*j<=n;j++){
        buf+=dfs(i*j);
    }
    buf%=2;
    int t=0;
    if(a[i]!=buf){
        t++;
        res++;
    }
    b[i]=t;
    return t;
}
int main(void){
    cin>>n;
    rep(i,n) cin>>a[i+1];
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    cout<<res<<endl;
    rep(i,n){
        if(b[i+1]!=0)cout<<i+1<<endl;
    }
}