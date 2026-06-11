#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define fast                                                                   \
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i,a,n) for (i = a; i <= n; i++)
#define F first
#define S second
#define pii pair<int,int>
#define sz size()
#define all(v) v.begin(),v.end()
#define pb push_back
#define pf push_front    
#define PB pop_back
#define pll pair<long long, long long>
#define vi vector<int>
#define vl vector<int>
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
const int N = 200005;
const int MOD = 998244353 ;


int powerm(ll a,ll b,ll m=mod){
    a %= m;
    int res = 1%m;
    while(b > 0){
        if(b & 1)res = (res * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}


void solve(){
    int n, a, b;
    cin>>n>>a>>b;
    int a1 = 1, a2 = 1, b1 = 1, b2 = 1;
    for(int i= 1; i <= a; i++){
        a2 *= (n - a + i);
        a2 %= mod;
        a1 *= i;
        a1 %= mod;
    }
    for(int i= 1; i <= b; i++){
        b2 *= (n - b + i);
        b2 %= mod;
        b1 *= i;
        b1 %= mod;
    }
    int ans = powerm(2,n) - 1 - ((a2 * powerm(a1,mod - 2))%mod) - ((b2 * powerm(b1,mod - 2))%mod);
    ans %= mod;
    if(ans < 0)ans += mod;
    cout<<ans;
}

int32_t main() {
    fast
    int t;
    t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
