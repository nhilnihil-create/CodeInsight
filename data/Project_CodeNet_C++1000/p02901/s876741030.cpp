#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
   int n,m;
   cin >> n >> m;
   vector<int>a(m);
   vector<int>k(m,0);
   for(int i = 0;i<m;i++){
    int b;
    cin >> a[i] >> b;
    for(int j = 0;j<b;j++){
        int c;cin >> c;
        c--;c = 1<<c;
        k[i] = (k[i]|c);
    }
   }
   vector<vector<int>>dp(m+1,vector<int>((1<<n),INF32));
   for(int i = 0;i<=m;i++) dp[i][0] = 0;
   for(int i = 1;i<=m;i++){
    for(int j = 0;j<(1<<n);j++){
        dp[i][j] = min(dp[i-1][j],dp[i][j]);
        dp[i][(j|k[i-1])] = min(dp[i-1][j]+a[i-1],dp[i][(j|k[i-1])]);
    }
   }
   if(dp[m][(1<<n)-1] == INF32) cout << -1;
   else cout << dp[m][(1<<n)-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}