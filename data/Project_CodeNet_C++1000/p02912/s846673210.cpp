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

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<int> data;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        data.push(d);
    }
    for (int i = 0; i < M; i++) {
        int a = data.top();
        data.pop();
        data.push(floor(a / 2));
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int a = data.top();
        data.pop();
        ans += ll(a);
    }
    cout << ans << endl;

}
