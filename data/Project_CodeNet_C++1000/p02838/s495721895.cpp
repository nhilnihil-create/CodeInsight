#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

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
     ll n;cin >> n;
     vector<ll>a(n);
     for(int i = 0;i<n;i++) cin >> a[i];
     ll ans = 0;
     for(int i = 0;i<=60;i++){
        ll c0 = 0;ll c1 = 0;
        for(int j = 0;j<n;j++){
            if(a[j]&1) c1++;
            else c0++;
            a[j] /= 2;
        }
        ans += (((c0*c1)%mod)*modpow(2,i,mod))%mod;
        ans %= mod;
     }
     cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}