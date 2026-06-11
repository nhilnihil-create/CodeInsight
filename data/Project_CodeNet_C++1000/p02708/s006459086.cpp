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
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll i = K; i < N + 2; i++) {
        ll minsum = i * (i - 1) / 2;
        ll maxsum = N * (N + 1) / 2 - (N - i) * (N - i + 1) / 2;
        ans += maxsum - minsum + 1;
        ans %= 1000000007;
    }
    cout << ans << endl;
}
