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
int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int k = n / 2;
    int m = a[k - 1];
    int m1 = a[k];
    if (m == m1) {
        cout << 0 << endl;
    } else {
        cout << m1 - m << endl;
    }

    return 0;
}
