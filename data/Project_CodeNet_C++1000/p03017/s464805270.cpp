#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)

const int maxn = 5e5 + 1, mod = 1e9 + 7;

using namespace std;

bool v[1000][1000];
int d[1000][1000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a, b, c, d; string s;
    cin >> n >> a >> b >> c >> d >> s;
    --a; --b;
    if (c < d) {
        for (int i = a + 1; i < d; i++) {
            if (s[i] == '#' && s[i - 1] == '#') {
                cout << "No"; return 0;
            }
        }
        cout << "Yes";
        return 0;
    }
    for (int i = a + 1; i < c; i++) {
        if (s[i] == '#' && s[i - 1] == '#') {
            cout << "No"; return 0;
        }
    }
    for (int i = b; i < d; i++) {
        if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
            cout << "Yes"; return 0;
        }
    }
    cout << "No";
    return 0;
}
