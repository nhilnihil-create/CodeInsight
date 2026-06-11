#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
    
using namespace std;
using ll = long long;
using pii = pair<int, int>;
    
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 200200;
const double PI = acos(-1);
ll memo[maxn];

ll fexp(ll a, ll b){
    ll ans = 1;

    while (b){
        if (b&1){
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        b = b >> 1;
    }
    return ans;
}

ll fat(ll num){
    if (num <= 1) return 1;
    if (memo[num] != -1) return memo[num];
    return memo[num] = (num*fat(num-1))%mod;
}

ll combina(ll a, ll b){
    ll x = 1, y = 1;
    for (ll i=1; i<=b; i++){
        x = (x *(i+(a - b)))%mod;
        y = (y*i)%mod;
    }
    return (x*fexp(y, mod - 2))%mod;
}
int main(){
    ll n, a, b, x, y, cnt;
    memset(memo, -1, sizeof memo);
    cin >> n >> a >> b;

    ll ans = (fexp(2, n) - 1 + mod)%mod;
    ans = (ans - combina(n, a) + mod)%mod;
    ans = (ans - combina(n, b) + mod)%mod;

    cout << ans << endl;
    return 0;
}