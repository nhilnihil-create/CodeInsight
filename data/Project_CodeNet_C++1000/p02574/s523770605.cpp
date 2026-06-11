#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int maxn = 2e5 + 5;
typedef long long ll;
typedef uint64_t HT;
const int mod = 1e9 + 7;
const int test_time = 8;
int quickPow(int a, int b, int p) {
    a %= p;
    int ans = 1;
    while (b) {
        if (b & 1) ans = (1LL * ans * a) % p;
        b >>= 1;
        a = (1LL * a * a) % p;
    }
    return ans;
}
bool millerRabbin(int n) {
    if (n < 3) return n == 2;
    int a = n - 1, b = 0;
    while (a % 2 == 0) a /= 2, ++b;
    // test_time 为测试次数,建议设为不小于 8
    // 的整数以保证正确率,但也不宜过大,否则会影响效率
    for (int i = 1, j; i <= test_time; ++i) {
        int x = rand() % (n - 2) + 2, v = quickPow(x, a, n);
        if (v == 1 || v == n - 1) continue;
        for (j = 0; j < b; ++j) {
            v = (long long) v * v % n;
            if (v == n - 1) break;
        }
        if (j >= b) return 0;
    }
    return 1;
}

bool prime_diecom(int n, map<int, int> &ma) {
    map<int, int> tmp;
    tmp.clear();
    for (int i = 2; i <= n; i++) {
        while (n != i) {
            if (n % i == 0) {
                n = n / i;
                if (ma.count(i)) return false;
                tmp[i] = 1;
            } else
                break;
        }
        if (millerRabbin(n)) {
            if (ma.count(n)) return false;
            tmp[n] = 1;
            break;
        }
    }
    for (auto &i : tmp) ma.insert(i);
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int gcd;
    map<int, int> ma;
    ma.clear();
    bool pairwise = true, setwise = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (pairwise) pairwise = prime_diecom(a[i], ma);
        if (i == 1)
            gcd = a[i];
        else
            gcd = __gcd(a[i], gcd);
    }
    setwise = (gcd == 1);
    if (pairwise) {
        cout << "pairwise coprime\n";
    } else if (setwise) {
        cout << "setwise coprime\n";
    } else {
        cout << "not coprime\n";
    }
    return 0;
}