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
void build(int i){
    hsh[i] = (((s[i-1]-'0'))%mod+hsh[i-1]*10%mod)%mod;
}
int tinh(int l, int r){
    return (hsh[r]-hsh[l-1]*Pow[r-l+1]+mod)%mod;
}
int comb(int k, int n){
    return fact[n]*luythua(fact[k],mod-2)%mod*luythua(fact[n-k],mod-2)%mod;
}
int a[MAXN];
signed main(){                                                                                                                                                                                                                                                                                                  ios_base::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int cnt = 0;
    for(int i=1;i<=n;i++)if(a[i]>=m)cnt++;
    cout<<cnt;
}
