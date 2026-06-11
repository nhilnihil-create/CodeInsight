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
#include <bitset> // bitset
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

void f(vector<vi> &data, vi &num, vll &ans, ll sum, int n) {
    sum += ll(num[n]);
    ans[n - 1] = sum;
    for (int x : data[n]) {
        if (ans[x - 1] != -1) {
            continue;
        }
        f(data, num, ans, sum, x);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vi> data(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        data[a].push_back(b);
        data[b].push_back(a);
    }
    vi num(N + 1, 0);
    for (int i = 0; i < Q; i++) {
        int p, x;
        cin >> p >> x;
        num[p] += x;
    }
    vll ans(N, -1);
    f(data, num, ans, 0, 1);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
