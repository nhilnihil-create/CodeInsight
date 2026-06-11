#include <bits/stdc++.h>
using namespace std;

typedef int64_t Int;
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << endl; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) cout << " ";
    cout << fixed << setprecision(15) << head;
    print_space_enable = true;
    print(std::forward<Tail>(tail)...);
}

template<typename T>
void print(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << v[i];
    }
    std::cout << std::endl;
}

Int dp[2001][2001];

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n);
    for (Int i = 0; i < (Int)n; i++) {
        cin >> a[i];
    }
    priority_queue<pair<Int, Int>> q;
    for (Int i = 0; i < (Int)n; i++) {
        q.push({a[i], i});
    }
    for (Int i = 0; i < n; i++) {
        pair<Int, Int> p = q.top();
        for (Int j = 0; j <= i; j++) {
            dp[j + 1][i - j] = max(dp[j + 1][i - j], dp[j][i - j] + p.first * abs(j - p.second));
            dp[j][i - j + 1] = max(dp[j][i - j + 1], dp[j][i - j] + p.first * abs(n - 1 - (i - j) - p.second));
        }
        q.pop();
    }
    // for (Int i = 0; i <= n; i++) {
    //     for (Int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    Int res = 0;
    for (Int i = 0; i < (Int)n; i++) {
        res = max(res, dp[i][n - i]);
    }
    print(res);
    return 0;
}