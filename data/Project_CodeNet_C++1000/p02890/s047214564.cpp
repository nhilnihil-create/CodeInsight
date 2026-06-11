/*input
3
2 1 2
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<ll,ll>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
const ll INF64=4e15;
const int INF=0x3f3f3f3f;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
ll mult(ll a,ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=mult(res,a);
        a=mult(a,a);
        b>>=1;
    }
    return res;
}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
int sum[maxn],cnt[maxn],ans[maxn];
int main(){
    int n;
    cin>>n;
    REP(i,n){
        int a;
        cin>>a;
        ++sum[++cnt[a]];
    }
    int i=0;
    ll acc=0;
    for(int t=n;t>0;t--)
    {
        while(acc>=i*t)acc+=sum[++i];
        ans[t]=i-1;
    }
    REP(i,n) cout<<ans[i+1]<<'\n';
}
