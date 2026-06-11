#include <bits/stdc++.h>
using namespace std;
#define int long long
#define en '\n'
const int MAXN = 1e6+69;
const int INF = 1e18;
const int mod = 1e9+7;
struct vl{
    int x,y;
    bool operator<(vl t)const{
        if(x==t.x)return (y<t.y);
        return x<t.x;
    }
};
map<int,int>mp;
int q;
int m,p,n,k;
int x,y,z;
int a[MAXN],b[MAXN];
int cnt;
set<int> s;
int luythua(int x, int y){
    if(y==0)return 1;
    if(y==1)return x%mod;
    int k = luythua(x,y/2);
    if(y%2==0)return k*k%mod;
    return k*k%mod*x%mod;
}
int fact[MAXN];
int comb(int k, int n){
    return fact[n]*luythua(fact[k],mod-2)%mod*luythua(fact[n-k],mod-2)%mod;
}
signed main(){                                                                                                                                                                                                                         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>x>>y;
    if((x+y)%3!=0){
        cout<<0;
        return 0;
    }
    int k = (x+y)/3;
    fact[0]=1;
    for(int i=1;i<=1000000;i++){
        fact[i]=fact[i-1]*i%mod;
    }
    if(min(x,y)<k){
        cout<<0;
        return 0;
    }
    cout<<comb(min(x,y)-k,k)%mod;
}