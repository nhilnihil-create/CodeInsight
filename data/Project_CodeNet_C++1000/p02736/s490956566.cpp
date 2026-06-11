/*input
10
2311312312
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld eps=1e-6;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
ll sub(ll a,ll b){
    ll x=a-b;
    while(x<0) x+=MOD;
    while(x>MOD) x-=MOD;
    return x;
}
ll mult(ll a,ll b){
    return (a*b)%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
const ll maxn=1e6+5;
const ll maxlg=__lg(maxn)+2; 
int n;
int fac[maxn];
int c[maxn];
int main(){
    cin>>n;
    string s;
    cin>>s;
    REP(i,n) s[i]--;
    REP1(i,n-1) fac[i]=fac[i-1]+__builtin_ctz(i);
    REP(i,n){
        c[i]=fac[n-1]-fac[i]-fac[n-i-1];
        if(c[i]==0) c[i]=1;
        else c[i]=0;
    }
    ll ans=0;
    REP(i,n){
        ans+=(s[i]-'0')*(c[i]);
    }
    if(ans%2==1){
        cout<<1;
        return 0;
    }
    REP(i,n){
        if(s[i]=='1'){
            cout<<0;
            return 0;
        }
        if(s[i]=='2') s[i]='1';
    }
    ans=0;
    REP(i,n){
        ans+=(s[i]-'0')*c[i];
    }
    if(ans%2==1){
        cout<<2;
        return 0;
    }    
    cout<<0;
}