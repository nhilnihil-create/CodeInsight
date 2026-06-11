#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0);
    if(n < sum) {
        cout << -1 << endl;
    } else {
        cout << n - sum << endl;
    }
    return 0;
}