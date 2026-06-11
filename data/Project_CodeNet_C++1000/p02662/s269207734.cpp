#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define PI 3.141592653L
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = (ll)1e18;
const int N = 2e5 + 5;
const ll MOD = 998244353;

int parent[N];

int gcd(int a, int b) { 
    if (a == 0) 
        return b;  
    return gcd(b%a, a);  
} 
   
int lcm(int a, int b) {  
    return (a*b)/gcd(a,b);  
} 

ll pow(ll x, ll y, ll p) {
    if(y == 0) return 1;
    ll res = 1;
    x %= p;
    if(x == 0) return 0LL;
    while(y > 0) {
        if(y & 1) res = (res*x) % p;
        y >>= 1;
        x = (x*x) % p;
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

int main()
{
    IOS
    int n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<ll>> dp(n+1, vector<ll>(s+1, 0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=s;j++) {
            dp[i+1][j] += (dp[i][j] * 2) % MOD;
            if(j - a[i] >= 0) dp[i+1][j] += dp[i][j-a[i]];
            dp[i+1][j] %= MOD;
        }
    }
    cout << dp[n][s] << endl;
    return 0; 
}

