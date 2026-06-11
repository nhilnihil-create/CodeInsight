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
    int N, M;
    int MOD = 1000000007;
    cin >> N >> M;
    vb data(N + 1, true);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        data.at(a) = false;
    }
    vi dp(N + 1, 0);
    dp.at(0) = 1;
    if (data[1]) {
        dp[1] = 1;
    }
    for (int i = 2; i < N + 1; i++) {
        if (data[i - 1]) {
            dp[i] += dp[i - 1];
        }
        if (data[i - 2]) {
            dp[i] += dp[i - 2];
        }
        dp[i] %= MOD;
    }
    cout << dp[N] << endl;
}