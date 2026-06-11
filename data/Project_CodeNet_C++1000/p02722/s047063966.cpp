#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second
 
// rep(i, 0, sz(v)) cout << v[i] << " \n"[i==sz(v)-1];
 
////////////////////////////////////////////////////////

map<ll, ll> PrimeFactorization(ll n){
    map<ll, ll> mp;
    Rep(i, 2, sqrt(n)){
        while(n%i == 0){
            mp[i]++;
            n /= i;
        }
        if(n == 1) break;
    }
    if(n != 1) mp[n]++;
    return mp;
}

// 約数列挙
vector<long long> divisor(long long n){
    vector<long long> div;
    for(long long i = 1; i*i <= n; i++){
        if(n%i == 0){
            div.push_back(i);
            if(i*i != n) div.push_back(n/i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}

int main() {
    ll n; cin >> n;
    map<ll, ll> mp = PrimeFactorization(n-1);
    ll ans = 0;
    ll a = 1;
    for(auto it : mp) a *= it.second+1;
    ans += a - 1;

    // co(ans);

    Vl div = divisor(n);
    rep(i, 0, sz(div)){
        ll k = div[i];
        if(k == 1) continue;
        ll N = n;
        while(N%k == 0 && N >= k) N /= k;
        if(N%k == 1) ans++;
    }

    co(ans);

    return 0;
}
 