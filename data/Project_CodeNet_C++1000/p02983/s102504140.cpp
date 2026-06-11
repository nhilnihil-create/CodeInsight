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

int main() {
    Int l, r;
    cin >> l >> r;
    Int res = INF;
    for (Int i = l; i <= min(l + 2019, r); i++) {
        for (Int j = i + 1; j <= min(l + 2019, r); j++) {
            Int x = i % 2019;
            Int y = j % 2019;
            res = min(res, x * y % 2019);
        }
    }
    print(res);
    return 0;
}
