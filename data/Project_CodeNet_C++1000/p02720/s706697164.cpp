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

void f(vll &data, int n, ll num) {
    data.push_back(num);
    if (n == 10) {
        return;
    }
    for (ll i = -1; i <= 1; i++) {
        ll add = (num % 10) + i;
        if (add >= 0 && add <= 9) {
            f(data, n + 1, num * 10 + add);
        }
    }
}

int main() {
    int K;
    cin >> K;
    vll data;
    for (ll i = 1; i < 10; i++) {
        f(data, 1, i);
    }
    sort(data.begin(), data.end());
    cout << data[K - 1] << endl;
}
