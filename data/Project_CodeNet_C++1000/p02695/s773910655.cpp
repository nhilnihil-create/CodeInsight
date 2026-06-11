#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
typedef pair<int, int> P;
typedef long long ll;
int n, m, q;
int a[100];
int b[100];
int c[100];
int d[100];
int ans = 0;
void rec(int i, int num, vector<int> v)
{
    if (i == n)
    {
        int res = 0;
        for (int i = 0; i < q; i++)
        {

            if (v[b[i] - 1] - v[a[i] - 1] == c[i])
            {
                res += d[i];
            }
        }
        ans = max(ans, res);
        return;
    }
    for (int j = num; j < m; j++)
    {
        v[i] = j;
        rec(i + 1, j, v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    rep(i, q)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<int> tmp(n);
    rec(0, 0, tmp);
    cout << ans << endl;
}