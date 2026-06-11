#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n);
    b = a;
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int mx1 = b[0], mx2 = b[1];
    int id1 = -1;
    rep(i, n)
    {
        if (mx1 == a[i] && id1 == -1)
            id1 = i;
    }
    rep(i, n)
    {
        if (i == id1)
            cout << mx2 << endl;
        else
            cout << mx1 << endl;
    }
    return 0;
}