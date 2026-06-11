#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll oo = 1e18;
const ll mod = 1e9 + 7,maxn = 1000010;
const double PI = acos(-1);
vector<ll> fat(maxn), inv(maxn);
ll memo[30][30];

ll fexp(ll base, ll p){
    ll ans = 1;

    while (p){
        if(p&1) ans = (ans * base)%mod;
        base = (base * base)% mod;
        p = p >> 1;
    }
    return ans;
}

void init(){
    fat[0] = fat[1] = inv[1] = 1;
    for (ll i=2; i<maxn; i++){
        fat[i] = (fat[i-1] * i)%mod;
        inv[i] = fexp(fat[i], mod-2);
    }
}

ll combina(ll n, ll k){
    if (n == k || k == 0) return 1;
    if (n < k) return 0;

    return (((fat[n] * inv[k])%mod)*inv[n - k])%mod;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, n;
    cin >> n >> a >> b;

    if (a == 0){
        cout << "0" << endl;
        return 0;
    }
    else if (b == 0){
        cout << n << endl;
    }
    else {
        cout << ((n/(a+b))*a) + min(a, n%(a+b)) << endl;
    }
    return 0;
}