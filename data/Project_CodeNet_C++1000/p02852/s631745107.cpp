#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    int n,m;
    string s;
    cin>>n>>m>>s;
    int x=0,y=0;
    rep(i,n){
        if(s[i]=='1') x++;
        else x=0;
        y=max(y,x);
    }
    if(y>=m){
        cout<<-1<<"\n";
        return 0;
    }
    ll dp[200001],d[200001];
    dp[n]=0;
    d[0]=n;
    ll p=0,inf=1e18;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            dp[i]=inf;
            continue;
        }
        if(d[p]-i>m) p++;
        dp[i]=p+1,d[p+1]=i;
    }
    int a=dp[0],b=0;
    rep(i,n+1) if(a>dp[i]) cout<<i-b<<" ",a=dp[i],b=i;
    cout<<"\n";
}