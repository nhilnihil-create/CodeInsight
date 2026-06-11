#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
const int mod=1000000007;
int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1,-1);
    rep(i,m){
        int x;cin>>x;
        a[x]=0;
    }
    a[0]=1;
    if(a[1]==-1)a[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==0)continue;
        a[i]=a[i-1]+a[i-2];
        a[i]%=mod;
    }
    cout<<a[n]<<endl;
}