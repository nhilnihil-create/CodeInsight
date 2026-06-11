#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e6+69;
const int INF = 1e10;
const int mod = 1e9+7;
int m,n,k,q;
string s;
int hsh[MAXN];
int Pow[MAXN];
int fact[MAXN];
struct vl{
    int x,y;
    bool operator<(vl t)const{
        if(x==t.x)return y<t.y;
        return x<t.x;
    }
};
int luythua(int x, int y){
    if(y==0)return 1;
    if(y==1)return x%mod;
    int k = luythua(x,y/2);
    if(y%2==0)return k*k%mod;
    return k*k%mod*x%mod;
}
int a[MAXN],b[MAXN];
int c[MAXN];
int dp[MAXN];
signed main(){                                                                                                                                                                                                                                                                                                  ios_base::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<b[i];j++){
            cin>>k;
            k--;
            c[i]|=(1<<k);
        }
    }
    dp[0]=1;
    for(int i=1;i<(1<<n);i++)dp[i]=INF;
    for(int mask = 0;mask<(1<<n);mask++){
        if(dp[mask]!=INF){
            for(int i=1;i<=m;i++){
                dp[mask|c[i]]=min(dp[mask|c[i]],dp[mask]+a[i]);
            }
        }
    }
    if(dp[(1<<n)-1]!=INF)cout<<dp[(1<<n)-1]-1;
    else cout<<-1;
}
