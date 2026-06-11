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

ll gcd (ll a, ll b) {
    ll x = min(a, b);
    ll y = max(a, b);
    if (y % x == 0) {
        return x;
    }
    else {
        return gcd(y % x, x);
    }
}

ll lcm (ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll ans = B - A + 1;
    ans -= (B / C) - (A / C);
    if (A % C == 0) {
        ans--;
    }
    ans -= (B / D) - (A / D);
    if (A % D == 0) {
        ans--;
    }
    ll E = lcm(C, D);
    ans += (B / E) - (A / E);
    if (A % E == 0) {
        ans++;
    }
    cout << ans << endl;
}