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
    int N;
    cin >> N;
    if (N < 10) {
        cout << N << endl;
    }
    else if (N < 100) {
        cout << 9 << endl;
    }
    else if (N < 1000) {
        cout << N - 90 << endl;
    }
    else if (N < 10000) {
        cout << 909 << endl;
    }
    else if (N < 100000) {
        cout << N - 9090 << endl;
    }
    else {
        cout << 90909 << endl;
    }
}
