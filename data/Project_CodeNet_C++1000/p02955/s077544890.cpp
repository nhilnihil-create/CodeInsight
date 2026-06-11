#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr double pi = asin(1) * 2;
constexpr ll mod = 1000000007;

template<class T>
class set2 : public set<T> {
private:
    typename set<T>::iterator back_itr() {
        auto e = this->end();
        e--;
        return e;
    }

public:
    T front() {
        if (this->empty()) throw;
        return *this->begin();
    }

    T back() {
        if (this->empty()) throw;
        return *this->back_itr();
    }

    void erase_front() {
        if (!this->empty()) this->erase(this->begin());
    }

    void erase_back() {
        if (!this->empty()) this->erase(this->back_itr());
    }
};

int n, k, a[500], s;

bool ok(int m) {
    if (s % m) return false;
    int b[500];
    for (int i = 0; i < n; i++) {
        b[i] = a[i] % m;
    }
    sort(b, b + n);
    int l = 0, r = n - 1, c = 0;
    while (l < r) {
        if (b[l] == 0) {
            l++;
            continue;
        }
        if (b[r] == 0) {
            r--;
            continue;
        }
        int v = min(b[l], m - b[r]);
        b[l] = b[l] - v;
        b[r] = (b[r] + v) % m;
        c += v;
    }
    return k >= c;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) s += a[i];
    for (int i = s; i > 0; i--) {
        if (ok(i)) {
            cout << i << endl;
            return 0;
        }
    }
}
