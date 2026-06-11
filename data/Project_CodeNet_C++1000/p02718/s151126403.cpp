#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    bool ok = true;
    rep(i, m) if (a[i] * 4 * m < sum) ok = false;
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}