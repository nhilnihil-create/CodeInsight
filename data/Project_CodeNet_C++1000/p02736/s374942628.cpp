#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int n;
    string s;
    cin >> n >> s;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        a[i] = s[i] - '1';
    }
    bool check = false;
    for (Int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            check = true;
        }
    }
    for (Int i = 0; i < n; i++) {
        if (check) {
            a[i] %= 2;
        } else {
            a[i] /= 2;
        }
    }
    Int cnt = 0;
    for (Int i = 0; i < n; i++) {
        cnt += a[i] * (n - 1 == (i | (n - 1 - i)));
        cnt %= 2;
    }
    dump(check ? cnt : cnt * 2);
    return 0;
}