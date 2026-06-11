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
    Int n, k;
    cin >> n >> k;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Int sum1 = 0;
    for (Int i = 0; i < n - 1; i++) {
        for (Int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                sum1++;
                sum1 %= mod;
            }
        }
    }
    sum1 = sum1 * k % mod;
    Int sum2 = 0;
    for (Int i = 0; i < n; i++) {
        for (Int j = 0; j < n; j++) {
            if (a[i] > a[j]) {
                sum2++;
                sum2 %= mod;
            }
        }
    }
    Int mul = k * (k - 1) / 2;
    mul %= mod;
    sum2 = sum2 * mul % mod;
    print((sum1 + sum2) % mod);
}

int main() {
    solve();
    return 0;
}
