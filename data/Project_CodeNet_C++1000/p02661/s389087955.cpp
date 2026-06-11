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

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n), b(n);
    for (Int i = 0; i < (Int)n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(all(a));
    sort(all(b));
    if (n % 2 == 0) {
        double am = (double)(a[n / 2 - 1] + a[n / 2]) / 2.0;
        double bm = (double)(b[n / 2 - 1] + b[n / 2]) / 2.0;
        Int res = 2.0 * (bm - am);
        print(res + 1);
    } else {
        print(b[n / 2] - a[n / 2] + 1);
    }
    return 0;
}