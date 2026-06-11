
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#pragma GCC optimize("O2")
#define sz(x) ((long long)(x).size())
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define leastsigbit(x)     __builtin_ffs(x)
#define mod             1e9+7
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define tt ll tt;cin >> tt;while(tt--)
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n";}
const double PI = acos(-1);
ll power(ll a,ll b,ll m=mod){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}
const int MAXN = 2e5+ 10;
const ll inf = 1e18;

int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}
int32_t main() {
    fio
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x = a[0];
    int ans = 0;
    for (int j = 1; j < n; ++j) {
        ans+=max(0ll,x - a[j]);
        x = max(x,a[j]);
    }
    cout << ans << endl;

}




