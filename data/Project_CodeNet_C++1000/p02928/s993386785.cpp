#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
ll modpow(ll a, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll count_inside = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(a[i] > a[j]) count_inside++;
        }
    }
    ll ans = 0;
    ans += k * count_inside % mod;

    ll count_outside = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] > a[j]) count_outside++;
        }
    }
    //cout << ans << endl;
    ll kousu = k * (k - 1) / 2;
    ans += kousu % mod * count_outside % mod;
    ans %= mod;
    cout << ans << endl;
}
