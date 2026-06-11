#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
ii a[N];
int l1[N], l2[N], r1[N], r2[N];
int n, t;
ll sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        r1[i] = r2[i] = n + 1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        a[i] = {t, i};
    }
    sort(a + 1, a + n + 1);
    set<int> lst;
    set<int> rst;
    for (int i = n; i > 0; --i) {
        int cur = a[i].second; // original index
        auto it1 = rst.lower_bound(cur);
        if (it1 != rst.end()) {
            r1[cur] = *it1;
            auto it2 = next(it1);
            if (it2 != rst.end()) {
                r2[cur] = *it2;
            }
        }
        auto it3 = lst.lower_bound(-cur);
        if (it3 != lst.end()) {
            l1[cur] = -*it3;
            auto it4 = next(it3);
            if (it4 != lst.end()) {
                l2[cur] = -*it4;
            }
        }
        rst.insert(cur);
        lst.insert(-cur);
    }
    for (int i = 1; i <= n; ++i) {
        int k = a[i].second;
        sum += 1LL * (l1[k] - l2[k]) * (r1[k] - k) * a[i].first;
        sum += 1LL * (k - l1[k]) * (r2[k] - r1[k]) * a[i].first;
    }
    cout << sum << endl;

    return 0;
}
