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
int n, cnt;
const int N = 24;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0 && i < n - 1) {
            if (a[i] > a[i - 1] && a[i] < a[i + 1]) {
                ++cnt;
            } else if (a[i] < a[i - 1] && a[i] > a[i + 1]) {
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
