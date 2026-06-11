#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    sort(d.begin(), d.end());
    cout << d[n / 2] - d[n / 2 - 1] << endl;
    return 0;
}