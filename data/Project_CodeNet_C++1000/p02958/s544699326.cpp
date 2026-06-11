#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    bool ok = true;
    rep(i, n - 1) if (p[i] > p[i + 1]) ok = false;
    if (ok)
    {
        cout << "YES" << endl;
        return 0;
    }
    rep(i, n)
    {
        rep(j, n)
        {
            if (p[i] > p[j])
            {
                swap(p[i], p[j]);
                ok = true;
                rep(k, n - 1) if (p[k] > p[k + 1]) ok = false;
                if (ok)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                swap(p[i], p[j]);
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}