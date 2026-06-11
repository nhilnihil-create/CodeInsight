#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e6+69;
const int INF = 1e10;
const int mod = 1e9+7;
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
int m,n,q,k,l,x,y,z;
int a[MAXN];
int dp[MAXN];
string s,t,r;
signed main(){                                                                                                                                                                                                                                                                                                  ios_base::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);
    cin>>s>>t;
    cin>>m>>n;
    cin>>r;
    if(r==s)m--;
    if(r==t)n--;
    cout<<m<<' '<<n;
}
