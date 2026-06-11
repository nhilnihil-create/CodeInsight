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

bool check(int sum) {
    int n = floor(sqrt(sum));
    if (n * n == sum) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<vi> data(N, vi(D));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> data[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < D; k++) {
                sum += (data[i][k] - data[j][k]) * (data[i][k] - data[j][k]);
            }
            if (check(sum)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
