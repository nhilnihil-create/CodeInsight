#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

// using mint = modint1000000007;
// using mint = modint998244353;

typedef int64_t Int;
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << '\n'; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) std::cout << " ";
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
    std::cout << '\n';
}

void solve() {
    Int n;
    cin >> n;
    Int res = 0;
    for (Int i = 1; i <= n; i++) {
        for (Int j = i; j <= n; j += i) {
            res += j;
        }
    }
    print(res);
}

int main() {
    solve();
    return 0;
}
