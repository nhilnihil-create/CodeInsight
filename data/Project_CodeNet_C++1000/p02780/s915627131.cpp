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

ld f(ld a) {
    ld ans = (1 + a) / 2;
    return ans; 
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ld> data(N);
    for (int i = 0; i < N; i++) {
        ld a;
        cin >> a;
        data[i] = f(a);
    }
    ld ans = 0;
    for (int i = 0; i < K; i++) {
        ans += data[i];
    }
    ld ansa = ans;
    for (int i = 0; i < N - K; i++) {
        ansa -= data[i];
        ansa += data[K + i];
        ans = max(ans, ansa);
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}
