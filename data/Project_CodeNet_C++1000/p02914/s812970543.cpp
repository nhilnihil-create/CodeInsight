/*input
20
1008288677408720767 539403903321871999 1044301017184589821 215886900497862655 504277496111605629 972104334925272829 792625803473366909 972333547668684797 467386965442856573 755861732751878143 1151846447448561405 467257771752201853 683930041385277311 432010719984459389 319104378117934975 611451291444233983 647509226592964607 251832107792119421 827811265410084479 864032478037725181
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
typedef long long int ll;
#define ld long double
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define sz(_a) (ll)(_a.size())
#define FILL(n) memset(n,0,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
const ll maxn=200005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;

ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
ll sub(ll x,ll y){
    return (x % MOD - y % MOD + MOD) % MOD;
}
ll mult(ll a,ll b) 
{ 
    return ((a%MOD)*(b%MOD))%MOD;
} 
#define int ll
int arr[maxn];
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int ans=0;
    REP(i,n){
        cin>>arr[i];
        ans^=arr[i];
    }
    REP(i,n) arr[i]=(arr[i]|ans)^ans;
    vector<int> v;
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--){
        for(auto x:v) arr[i]=min(arr[i],arr[i]^x);
        if(arr[i]) v.pb(arr[i]);
    }
    int z=0;
    for(auto x:v) z=max(z,x^z);
    cout<<2*z+ans;
}