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

int f(int n) {
    if (n == 1) {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans *= 10;
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vi> data(M, vi(2));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> data.at(i).at(j);
        }
    }
    for (int i = 0; i <= 1000; i++) {
        if (f(N + 1) <= i) {
            break;
        }
        if (i < f(N)) {
            continue;
        }
        bool check = false;
        for (int j = 0; j < M; j++) {
            int a;
            if (data.at(j).at(0) == N) {
                a = i % 10;
            }
            else {
                a = (i / f(N + 1 - data.at(j).at(0))) % 10;
            }
            if (a != data.at(j).at(1)) {
                check = true;
                break;
            }
        }
        if (!check) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}