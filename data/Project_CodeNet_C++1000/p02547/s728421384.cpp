#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SZ(x) (int)((x).size())
#define xx first
#define yy second
#define pii pair<int, int>

const int N = 101;

int a[2][N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> a[j][i];
    bool w = 0;
    for (int i = 1; i < n - 1; i++) {
        bool t = 1;
        for (int j = -1; j <= 1; j++)
            t &= a[0][i + j] == a[1][i + j];
        w |= t;
    }
    cout << (w ? "Yes" : "No") << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
