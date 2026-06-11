#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=2e3+5;
ll dp[N][N];
ll maxn;

struct nobe{
ll v,p;
}a[N];

bool cmp(nobe a,nobe b){
return a.v>b.v;
}

int main(){
ll n;
cin>>n;
for(ll i=0;i<n;i++){
    cin>>a[i].v;
    a[i].p=i+1;
}
sort(a,a+n,cmp);
for(ll i=0;i<=n;i++)
    for(ll j=0;j<=n;j++){
    if(i+j==n) {
        maxn=max(maxn,dp[i][j]);
        break;
        }
    int k=i+j;
    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+abs(a[k].p-i-1)*a[k].v);
    dp[i][j+1]=max(dp[i][j+1],dp[i][j]+abs(a[k].p-n+j)*a[k].v);
}
cout<<maxn<<endl;
return 0;
}