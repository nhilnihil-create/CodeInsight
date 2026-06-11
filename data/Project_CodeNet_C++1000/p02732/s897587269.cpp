#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    unordered_map<int, int> table;
    rep(i, n)++ table[a[i]];

    ll sum = 0;
    for (auto i : table)
        sum += ll(i.second) * (i.second - 1) / 2;

    rep(i, n) cout << sum - (table[a[i]] - 1) << endl;
}