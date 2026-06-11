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

int main() {
    ll L, R;
    cin >> L >> R;
    if (R - L >= 2019) {
        cout << 0 << endl;
    }
    else {
        ll ans = 2018;
        for (ll i = L; i < R; i++) {
            for (ll j = i + 1; j <= R; j++) {
                ans = min(ans, (i * j) % 2019);
            }
        }
        cout << ans << endl;
    }
}