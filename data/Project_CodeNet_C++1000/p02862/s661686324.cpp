#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

ll mod = 1000000007;

ll modpow(ll x, ll n) {
    x %= mod;
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return (x * modpow(x, n - 1)) % mod;
    }
    else {
        return modpow((x * x) % mod, n / 2) % mod;
    }
}

ll comb(ll n, ll k) {
    ll x = 1;
    for (ll i = n - k + 1; i <= n; i++) {
        x = (x * i) % mod; 
    }
    ll y = 1;
    for (ll i = 1; i <= k; i++) {
        y = (y * i) % mod;
    }
    y = modpow(y, mod - 2);
    return (x * y) % mod;
}

int main() {
    int X, Y;
    cin >> X >> Y;
    ll ans = 0;
    int a = min(int(floor(X / 2)), Y);
    for (int i = a; i >= 0; i--) {
        if (2 * (X - (2 * i)) == Y - i) {
            int b = X - (2 * i);
            int k = min(i, b);
            ans = (ans + comb(ll(i + b), ll(k))) % mod;
        }
    }
    cout << ans << endl;
}
