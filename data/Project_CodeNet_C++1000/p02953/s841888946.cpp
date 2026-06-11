#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    rep(i, n - 1) if (h[i] < h[i + 1]) h[i + 1]--;
    bool ok = true;
    rep(i, n - 1) if (h[i] > h[i + 1]) ok = false;
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}