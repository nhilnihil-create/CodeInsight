#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll h, n;
    cin >> h >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    if(accumulate(a.begin(), a.end(), 0) >= h) {
        cout << "Yes" << endl;
        return 0;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
