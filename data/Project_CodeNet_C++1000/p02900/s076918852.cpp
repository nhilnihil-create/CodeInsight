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

ll gcd (ll a, ll b) {
    ll x = min(a, b);
    ll y = max(a, b);
    if (y % x == 0) {
        return x;
    }
    else {
        return gcd(y % x, x);
    }
}

int main() {
    ll A, B;
    cin >> A >> B;
    int count = 0;
    ll N = gcd(A, B);
    for (ll i = 2; i * i <= N; i++) {
        if (N % i != 0) {
            continue;
        }
        while(N %  i == 0) {
            N /= i;
        }
        count++;
    }
    if (N != 1) {
        count++;
    }
    cout << count + 1 << endl;
}
