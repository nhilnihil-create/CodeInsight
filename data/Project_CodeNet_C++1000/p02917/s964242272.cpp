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
const int N = 105;
int a[N];
int n, b;

int main() {
    cin >> n;
    int sum = 0;
    memset(a, 0x3f, sizeof a);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b;
        a[i] = min(a[i], b);
        a[i + 1] = min(a[i + 1], b);
        sum += a[i];
    }
    sum += a[n - 1];
    cout << sum << endl;
    return 0;
}
