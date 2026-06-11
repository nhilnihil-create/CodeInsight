#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    ll T1, T2;
    ll A1, A2;
    ll B1, B2;
    cin >> T1 >> T2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;
    ll P = (A1 - B1) * T1;
    ll Q = (A2 - B2) * T2;
    if(P > 0) {
        P = -P;
        Q = -Q;
    }
    if(P + Q < 0) {
        cout << 0 << endl;
        return 0;
    }
    if(P + Q == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    ll S = (-P) / (P + Q);
    ll T = (-P) % (P + Q);
    if(T == 0) {
        cout << S * 2 << endl;
        return 0;
    } else {
        cout << S * 2 + 1 << endl;
        return 0;
    }
}