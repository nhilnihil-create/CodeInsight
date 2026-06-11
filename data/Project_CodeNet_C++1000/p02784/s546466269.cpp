#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll sum = 0;
    rep(i, n) sum += a[i];
    if (sum >= h)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}