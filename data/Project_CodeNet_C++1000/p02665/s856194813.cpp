/*input
3
0 1 1 2
*/ 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<ll,ll>;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define MP make_pair
const ll INF64=4e17;
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
const ll maxn=1e5+5;
const ll maxlg=__lg(maxn)+5;
ll arr[maxn];
ll pref[maxn];
int main(){
    int n;
    cin>>n;
    if(n==0){
        int x;
        cin>>x;
        if(x!=1) cout<<-1;
        else cout<<1;
        return 0;
    }
    ll tot=0;
    REP(i,n+1){
        cin>>arr[i];
        tot+=arr[i];
    }
    ll ans=0;
    ll cur=1;
    REP(i,n+1){
        ans+=cur;
        if(cur<arr[i]){
            cout<<-1;
            return 0;
        }
        cur-=arr[i];
        cur*=2;
        tot-=arr[i];
        MNTO(cur,tot);
    }
    cout<<ans;
}
