#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ll long long
#define db double
#define el "\n"
#define ld long double
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
#define all(ds) ds.begin(), ds.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef vector< long long > vi;
typedef pair<long long, long long> ii;
typedef priority_queue <ll> pq;
#define o_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define graph vector<vi>

const ll mod = 1000000007;
const ll INF = (ll)1e18;
const ll MAXN = 1000006;

ll po(ll x, ll n ){ 
    ll ans=1;
     while(n>0){
         if(n&1) ans=(ans*x)%mod;
         x=(x*x)%mod;
         n/=2;
     }
     return ans;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    //cin >> T;
    while(T--){
        ll n;
        cin>>n;
        ll a[n];
        rep(i,n) cin>>a[i];
        sort(a, a+n);
        ll ans=0, l, r;
        for(int i=1; i<n-1; i++){
            l=i-1, r=n-1;
            for(;l>=0;l--){
                while(r>i && a[l]+a[i]<=a[r]) r--;
                ans+=r-i;
            }
        }
        cout<<ans<<el;
      }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}