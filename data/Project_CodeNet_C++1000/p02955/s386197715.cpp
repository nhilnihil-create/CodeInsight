#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

// enum_div 約数列挙O(√N)
// 順番はバラバラ
template<typename T>
vector<T> enum_div(T n) {
    vector<T> ret;
    for (T i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
            {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    REP(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    auto e = enum_div(sum);
    sort(e.rbegin(), e.rend());
    vector<int> b(n);
    REP(i, e.size()) {
        int total = 0;
        REP(j, n) {
            b[j] = a[j] % e[i];
            total += b[j];
        }
        sort(b.rbegin(), b.rend());
        int num = total / e[i];
        REP(j, num) {
            total -= b[j];
        }
        if (k >= total) {
            cout << e[i] << endl;
            break;
        }
    }
    return 0;
}