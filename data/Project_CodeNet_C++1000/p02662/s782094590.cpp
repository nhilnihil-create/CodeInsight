#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e9+7;
ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define w(t) while(t--)
#define c(n); cin>>n;
#define p(n) cout<<n;
#define pl(n) cout<<n<<"\n";
#define ps(n); cout<<n<<" ";
#define F first
#define S second
#define pb(a) push_back(a)
#define all(x) (x).begin(), (x).end()
#define ull unsigned long long
#define vll vector<ll>
#define vii vector<ii>
#define mkp make_pair
#define ld long double
#define arrin(a,n) f(i,0,n){cin>>a[i];}
#define arrout(a,n) f(i,0,n){cout<<a[i]<<" ";}
#define printclock cerr<<"Time : "<<10000005*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define PI (2*acos(0))
#define EPS 1e-18
const long long N = 1e5+5;
vll visit,dist,taken;
vector<vll> adj;
vector<vii> adj2;
priority_queue<ii,vector<ii>, greater<ii> > pq;
ll bit[N];
ll an[N][35];
ll depth[N]={0};
ll siz;
ll res = 0;
ll lcm(ll a,ll b){return (a * b) / __gcd(a,b);}
ll gcd(ll a,ll b){return __gcd(a,b);}
ll power(ll a,ll b){if(b == 0)return 1;if(b == 1)return a;ll ans = power(a,b/2) % MOD;ans *= ans;ans %= MOD;if(b % 2 == 1)ans *= a;return ans%MOD;}
ll inverse(ll x){x%=MOD;return power(x,MOD-2);}
void BITup(ll k, ll x){while(k <= siz){bit[k]+=x;k += k & -k;}}
ll BITq(ll k){ll s=0;while(k>=1){s+=bit[k];k -= k &-k;}return s;}
struct point{ll x,y,idx;};
int main(void){
    fastio;
    ll n,s;
    cin>>n>>s;
    ll arr[n];
    arrin(arr,n);
    ll dp[n+1][s+1];
    ///dp[i][j] = ways to choose the sum j with the first i elements
    ///base case dp[0][0] = 2^n (all subsets) and all other dp[0][j] = 0
    f(i,1,s+1){
        dp[0][i] = 0;
    }
    ll inv = inverse(2);
    dp[0][0] = power(2,n);
    f(i,1,n+1){
        f(j,0,s+1){
            ///surely in the first i elements there are dp[i-1][j] solution
            dp[i][j] = dp[i-1][j];
            ///however we must add the solution which uses the new element (arr[i-1])
            if(j >= arr[i-1]){
                ///dp[i][j] += (dp[i-1][j-arr[i-1]] / 2) because there are dp[i-1][j-arr[i-1]] sums that gives the sum j-arr[i-1] and we divided with 2
                ///because the half of the solutions of dp[i-1][j-arr[i-1]] don't have a subset with sum j
                dp[i][j] = (dp[i][j] + (dp[i-1][j-arr[i-1]] * inv) % MOD) % MOD;
            }
        }
    }
    cout<<dp[n][s];
}
