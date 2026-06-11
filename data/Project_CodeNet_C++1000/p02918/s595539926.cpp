#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 1e6 + 10;

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
    int n,k;cin >> n >> k;
    string s;cin >> s;
    int ans = 0;int cnt = 0;
    vector<char>v;
    for(int i = 0;i<n-1;i++){
        if(s[i]==s[i+1]) ans++;
    }
    char c = 'a';
    for(int i = 0;i<n;i++){
        if(s[i]!=c) {v.push_back(s[i]);c = s[i];}
        if(v.size()==3) {cnt++;v.clear();v.push_back(c);}
    }
    ans += min(k,cnt)*2;
    if(k>cnt&&v.size()==2) ans++;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
