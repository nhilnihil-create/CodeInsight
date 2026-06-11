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

const int N = 25;
int a[N];
int b[N];
int c[N];

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> c[i];
    }
    int sum = 0;
    int p = -1;
    for (int i = 1; i <= n; ++i) {
        int k = a[i];
        sum += b[k];
        if (k == p + 1)
            sum += c[p];
        p = k;
    }
    cout << sum << endl;
    return 0;
}
