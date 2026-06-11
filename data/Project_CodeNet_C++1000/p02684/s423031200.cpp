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
    ll K;
    cin >> N >> K;
    vi data(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        cin >> data[i];
    }
    vb check(N + 1, false);
    check[1] = true;
    int i = 1;
    ll count = 0;
    while (true) {
        if (check[data[i]] || count == K - 1) {
            i = data[i];
            count++;
            break;
        }
        check[data[i]] = true;
        i = data[i];
        count++;
    }
    if (count == K) {
        cout << i << endl;
        return 0;
    }
    K -= count;
    int j = i;
    count = 0;
    while (true) {
        if (data[j] == i || count == K - 1) {
            count++;
            j = data[j];
            break;
        }
        j = data[j];
        count++;
    }
    if (count == K) {
        cout << j << endl;
        return 0;
    }
    K %= count;
    for (int k = 0; k < K; k++) {
        i = data[i];
    }
    cout << i << endl;
}
