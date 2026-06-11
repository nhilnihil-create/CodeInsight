#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int MOD = 1e+9 + 7;

int main() {
    int n,m;cin>>n>>m;
    int a[m];rep(i,m)cin>>a[i];
    rep(i,m-1)if(a[i+1]-a[i]==1){
        cout<<0<<endl;
        return 0;
    }

  ll b[n+1],c[n+1];
    memset(b,0,sizeof(b));

    rep(i,n+1)c[i]=1;
    rep(i,m)c[a[i]]=0;
    if(c[1]==1)b[1]=1;
    if(c[2]==1)b[2]=b[1]+1;
    for(int i = 3;i <= n;++i){
        b[i]=b[i-1]*c[i-1]+b[i-2]*c[i-2];
        b[i]%=MOD;
    }
    
    cout<<b[n]<<endl;
	return 0;
}