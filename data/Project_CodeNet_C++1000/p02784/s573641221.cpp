#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    bool win = false;
    rep(i, n)
    {
        h -= a[i];
        if (h <= 0)
            win = true;
    }
    if (win)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}