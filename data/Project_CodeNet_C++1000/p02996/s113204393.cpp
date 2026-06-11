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
const int N = 2e5 + 5;
int n, t;
ii a[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        t += a[i].second;
        if (t > a[i].first) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
    return 0;
}
