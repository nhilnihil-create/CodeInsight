#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cstdlib>  // abs() for integer
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<double> V(n);
    rep(i, n) cin >> V[i];
    sort(V.begin(), V.end());
    double v[2][1100];
    rep(i, n) v[0][i] = V[i];
    v[1][0] = (v[0][0] + v[0][1]) / 2;
    for(int i = 1;i < n- 1; i++) v[1][i] = (v[1][i - 1] + v[0][i + 1]) / 2;
    cout << v[1][n - 2] << endl;
}