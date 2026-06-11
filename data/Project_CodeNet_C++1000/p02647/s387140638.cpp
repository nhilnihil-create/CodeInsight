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
   int n,k;cin >> n >> k;
   vector<int>a(n);

   for(int i = 0;i<n;i++) cin >> a[i];
   for(int j = 0;j<k;j++){
        vector<int>b(n,0);
        bool ok = 0;
    for(int i = 0;i<n;i++){
        int l = max(i-a[i],0);
        int r = min(i+a[i],n);
        b[l]++;
        if(r+1<n) b[r+1]--;
    }
    //for(int i = 0;i<n;i++) cout << b[i] <<' ';
    for(int i = 1;i<n;i++) b[i] += b[i-1];
    for(int i = 0;i<n;i++){
        a[i] = b[i];
        if(b[i]!=n) ok = 1;
    }
    if(!ok) break;
   }
   for(int i = 0;i<n;i++) cout << a[i] <<' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}