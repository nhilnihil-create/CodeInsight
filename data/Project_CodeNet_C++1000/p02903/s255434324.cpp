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

bool v[1001][1001];

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < b; i++)
        for (int j = 0; j < a; j++)
            v[i][j] = 1;
    for (int i = b; i < n - b; i++)
        for (int j = a; j < 2 * a; j++)
            v[i][j] = 1;
    for (int i = n - b; i < n; i++)
        for (int j = a; j < m; j++)
            v[i][j] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << v[i][j];
        cout << '\n';
    }
    return 0;
}
