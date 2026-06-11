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

int n;
const int N = 2e5 + 5;
int a[N];
int m1, m2;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > m1) {
            m2 = m1;
            m1 = a[i];
        } else if (a[i] > m2) {
            m2 = a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != m1) {
            cout << m1 << endl;
        } else {
            cout << m2 << endl;
        }
    }
    return 0;
}
