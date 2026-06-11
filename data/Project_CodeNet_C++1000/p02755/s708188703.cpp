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
    int A, B;
    cin >> A >> B;
    int ans;
    bool check = true;
    for (int i = floor(A * 12.5); i < (B + 1) * 10; i++) {
        if (floor(i * 0.08) == A && floor(i * 0.1) == B) {
            ans = i;
            check = false;
            break;
        }
    }
    if (check) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}