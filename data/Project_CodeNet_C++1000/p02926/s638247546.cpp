
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 105;
int n;
ll res;
ii a[N];

inline static bool cmp(ii &a, ii &b) {
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}
inline static ll D(ll x, ll y) {
    return x * x + y * y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(20) << fixed;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        ll x = a[i].first, y = a[i].second;
        res = max(res, D(x, y));
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            x += a[j].first;
            y += a[j].second;
            res = max(res, D(x, y));
        }
    }
    cout << sqrt(res) << endl;

    return 0;
}

