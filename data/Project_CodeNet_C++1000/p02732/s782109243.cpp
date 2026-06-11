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
    int N;
    cin >> N;
    vi data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    vll count(N + 1, 0);
    for (int x : data) {
        count[x]++;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (count[i] > 1) {
            ll j = count[i];
            ans += j * (j - 1) / 2;
        }
    }
    for (int i = 0; i < N; i++) {
        ll ansa = ans;
        if (count[data[i]] > 1) {
            ll j = count[data[i]];
            ansa -= j * (j - 1) / 2;
            ansa += (j - 1) * (j - 2) / 2;
        }
        cout << ansa << endl;
    }
}
