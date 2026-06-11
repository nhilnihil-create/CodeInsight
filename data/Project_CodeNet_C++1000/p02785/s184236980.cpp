#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    sort(h.begin(), h.end());

    ll sum = 0;
    rep(i, n - k) sum += h[i];
    cout << sum << endl;
}