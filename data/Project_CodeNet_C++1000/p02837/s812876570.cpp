#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define X first
#define Y second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
const int N = 20;
int n, m, d[N];
vector<pii> a[N];

int dem1(int va)
{
    int cnt = 0;
    while (va > 0)
    {
        cnt += (va & 1);
        va /= 2;
    }
    return cnt;
}

bool setup(int j)
{
    for (pii u : a[j]) {
        if (d[u.X] == -1)
        {
            d[u.X] = u.Y;
            if (u.Y == 1)
            {
                if (!setup(u.X)) {
                    return false;
                }
            }
        }
        else if (d[u.X] != u.Y) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        for (int j = 1; j <= m; ++j) {
            int x, y;
            cin >> x >> y;
            a[i].push_back(pii(x, y));
        }
    }
    int lim = (1 << n), record = -1;
    for (int i = 0; i < lim; ++i) {
        int num = dem1(i);
        bool kt = true;
        if (num <= record) continue;
        memset(d, -1, sizeof d);
        for (int j = 1; j <= n && kt; ++j)
            if ((1 << (j - 1)) & i)
            {
                if (d[j] == 1) continue;
                if (d[j] == 0) {
                    kt = false;
                    break;
                }
                if (!setup(j)) {
                    kt = false;
                    break;
                }
            }
            else if (d[j] == 1) kt = false;
        if (kt)
            record = num;
    }
    cout << record;
    return 0;
}

