#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <random>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
mt19937 mrand(random_device{}());
//const ll mod = 1000000007;
int rnd(int x) { return mrand() % x; }
//ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// head

int t;
int k,q;
int d[5005];
ll sumd = 0;
int posd = 0;
int solve(ll n,ll x,int mod)
{
    posd=0;
    sumd=0;
    for(int i=0;i<k;++i){
        if(d[i]%mod) posd++;
        sumd += d[i]%mod;
    }
    ll a = (n-1)/k;
    ll am = (n-1)%k;
    ll cnt = sumd/mod;
    ll mm = sumd%mod;
    ll cntmod = cnt*a+(mm*a)/mod;
    ll ans = a*posd - cntmod;
    ll b = mm*a%mod;

    x%=mod;
    if(x+b >= mod) ans--;
    x = (x+b)%mod;
    for(int i=0;i<am;++i) {
        ll y = (x+d[i])%mod;
        if(x<y) ans++;
        x=y;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
#ifdef RG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>k>>q;
    sumd=0;
    posd=0;
    for(int i=0;i<k;++i) {
        cin>>d[i];
    }
    int n,x,mod;
    for(int i=0;i<q;++i) {
        cin>>n>>x>>mod;
        cout<<solve(n,x,mod)<<endl;
    }
    return 0;
}
