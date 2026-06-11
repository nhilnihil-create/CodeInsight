#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> a(n + 1);
    int longest = 0;
    rep(i, n) cin >> a[i];
    a[n] = k + a[0];
    rep(i, n) longest = max(longest, a[i + 1] - a[i]);
    cout << k - longest << endl;
}