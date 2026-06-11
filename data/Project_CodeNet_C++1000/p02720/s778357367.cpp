#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define INF 1000000000000
#define MOD 1000000007
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cout << #x1 << ": " << x1 << endl
#define debug_2(x1, x2) \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3)                                                 \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << endl
#define debug_4(x1, x2, x3, x4)                                             \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5)                                         \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#ifdef _DEBUG
#define debug(...)                                                        \
    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) \
    (__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using ll = long long;
int K;

template <class T>
void printVector(const vector<T>& v) {
    for (auto value : v) {
        cout << value << " ";
    }
    cout << endl;
}

// https :  // drken1215.hatenablog.com/entry/2020/04/05/150900
void dfs(vector<ll>& A, ll val, int digit) {
    A.push_back(val);
    if (digit == 10) {
        return;
    }
    // 各項の値は val-1 ... val+1
    for (ll v = -1; v <= 1; ++v) {
        ll tail = (val % 10) + v;
        if (0 > tail || tail > 9) continue;
        ll nval = val * 10 + tail;
        dfs(A, nval, digit + 1);
    }
}

int main() {
    vector<ll> A;
    cin >> K;

    reps(val, 9) { dfs(A, val, 1); }

    sort(A.begin(), A.end());
    cout << A[K - 1] << endl;
    return 0;
}