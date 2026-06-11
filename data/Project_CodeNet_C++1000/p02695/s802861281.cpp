#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n, m, q;
const int MAX = 51;
vector<int> a(MAX), b(MAX), c(MAX), d(MAX);
int ans = 0;

int f(int x, int y, vector<int> &v)
{
    return v[y] - v[x];
}

void rec(vector<int> &v)
{
    if (v.size() == n)
    {
        int score = 0;
        rep(i, q)
        {
            if (c[i] == f(a[i], b[i], v))
                score += d[i];
        }
        ans = max(ans, score);
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (v.size() > 0 && v[v.size() - 1] > i)
            continue;
        v.push_back(i);
        rec(v);
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m >> q;
    rep(i, q)
    {
        int aa, bb;
        cin >> aa >> bb;
        aa--;
        bb--;
        a[i] = aa;
        b[i] = bb;
        cin >> c[i] >> d[i];
    }
    vector<int> v;
    rec(v);
    cout << ans << endl;
    return 0;
}