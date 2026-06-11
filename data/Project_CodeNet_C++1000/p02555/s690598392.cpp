#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define PI 3.141592653L
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = (ll)1e18;
const int N = 5e5 + 5;
const ll MOD = 1e9+7;
 
int parent[N];
 
int gcd(int a, int b) { 
    if (a == 0) 
        return b;  
    return gcd(b%a, a);  
} 
   
int lcm(int a, int b) {  
    return (a*b)/gcd(a,b);  
} 
 
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
 
int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
 
void Union(int x, int y) {
    int xPar = find(x), yPar = find(y);
    if(xPar != yPar) parent[xPar] = yPar;
}
 
ll nCr(ll n, ll r) {
    ll res = 1;
    for(ll i=1;i<=r;i++) {
        res = res * (n - r + i) / i;
        // is different from
        // res *= (n -r + i) / i;
    }
    return res;
}
 
int ask(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int v;
    cin >> v;
    return v;
}

void solve() {
    int s;
    cin >> s;
    vector<ll> dp(s + 1, 0);
    dp[0] = 1;
    for(int i=1;i<=s;i++) {
        for(int j=i;j>=3;j--) {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    dp[s] %= MOD;
    cout << dp[s] << endl;
    return;
} 

int main()
{
    IOS
    //int t;
    //cin >> t;
    //while(t--) solve();
    solve();
    return 0; 
}
