/**
 * author  : UshanGhosh
 * created : 2020-09-20 20:34:20
**/ 

#include<bits/stdc++.h>
using namespace std;

#define    ll      long long
#define    pii     pair<int,int>
#define    vii     vector<int>
#define    vcc     vector<char>
#define    pll     pair<long long, long long>
#define    mem     memset
#define    sof     sizeof
#define    co1     __builtin_popcountll
#define    PB      push_back
#define    UB      upper_bound
#define    LB      lower_bound
#define    MP      make_pair
#define    TS      to_string
#define    F       first
#define    S       second
#define    pi      acos(-1)
#define    mod     (int)1e9+7
#define    inf     (long long)1e18
#define    endl    '\n'

long long bigmod(long long a, long long b, long long M){
    if(b==0) return 1%M;
    ll x = bigmod(a,b/2,M);
    x=(x*x)%M;
    if(b%2==1) x=(x*a)%M;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c,d,e,f,i,j,k,m,n,o,x,y;
    cin>>n;
    ll ans = bigmod(10,n,mod);
    ll pans = 2*bigmod(9,n,mod);
    pans -= bigmod(8,n,mod);
    pans += mod;
    pans %= mod;
    ans -= pans;
    ans += mod;
    ans %= mod;
    cout<<ans<<"\n";
}