
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1010;
int m[N][N];
vector<int> E[500000];
int n, t, cur, p;
int id = 1;
int res[500000];
int ret = 1;
int C[500000];
bool ok = true;

bool dfs(int x) {
    res[x] = 1;
    C[x] = 1;
    for (int i : E[x]) {
        if (C[i] == 1) return false;
        if (C[i] == 2) {
            res[x] = max(res[x], res[i] + 1);
            continue;
        }
        if (!dfs(i)) return false;
        res[x] = max(res[x], res[i] + 1);
    }
    C[x] = 2;
    ret = max(ret, res[x]);
    return true;
}

inline static int getid(int x, int y) {
    if (x > y)
        swap(x, y);
    if (m[x][y] == 0) {
        m[x][y] = id++;
    }
    return m[x][y];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> t;
            --t;
            cur = getid(i, t);
            if (j > 0) {
                E[cur].push_back(p);
            }
            p = cur;
        }
    }
    for (int i = 1; i < id; ++i) {
        if (C[i] == 0) {
            if (!dfs(i)) {
                ok = false;
                break;
            }
        }
    }
    if (ok)
        cout << ret << endl;
    else
        cout << -1 << endl;

    return 0;
}

