//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <map>
using namespace std;

#define ii pair <int, int>
#define lli long long
#define pb push_back
#define X first
#define Y second

const int Mod = 1E9 + 7;
const int Inf = 1E9 + 7;
const int N = 30 + 10;

int n, a[N];
ii x[N][N];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++) cin >> x[i][j].X >> x[i][j].Y;
    }
}

void Solve()
{

    int res = 0;
    for (int i = 1; i < (1 << n); i++) {
        bool ok = true;
        int cnt = 0;
        for (int j = 1; j <= n; j++) if (i & (1 << j - 1)) {
            cnt++;
            for (int k = 1; k <= a[j]; k++) {
                int Next = x[j][k].X;
                bool ck = (i & (1 << Next - 1));
                if (ck != x[j][k].Y) ok = false;
               // if (i == 3) cout << j << " " << Next << " " << ck << " " << x[j][k].Y << endl;
            }
        }
        if (ok) res = max(res, cnt);
    }
    cout << res;
}

#define task "test"
int main()
{
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int testcase = 1;
    /// cin >> testcase;
    while (testcase--) {
        Input();
        Solve();
    }
}


