#include <bits/stdc++.h>
#define PREP(i, s, x) for(ll i = (s); i < (x); i++)
#define MREP(i, s, x) for(ll i = (s); i >= (x); i--)
#define REP(i, x) PREP(i, 0, x)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

// variable -------------------------------------------

constexpr ll INF = (1ll << 59);
constexpr ll MOD = 1000000007ll;

// structure ------------------------------------------

// function -------------------------------------------
ll f(ll a, ll b){
    return a / b;
}

// 最大公約数を計算 GCD
// 最小公倍数を計算 LCM
ll llgcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return llgcd(b, a % b);
}
ll lllcm(ll a, ll b){
    if(a == 0 || b == 0){
        return 1;
    }
    return a / llgcd(a, b) * b;
}

// main -----------------------------------------------

int main() {
    ll n;
    cin >> n;
    vector<P> ba(n);
    REP(i, n){
        ll a, b;
        cin >> a >> b;
        ba[i].first  = b;
        ba[i].second = a;
    }

    sort(ba.begin(), ba.end());

    ll now = 0;
    REP(i, n){
        now += ba[i].second;
        if(now > ba[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}