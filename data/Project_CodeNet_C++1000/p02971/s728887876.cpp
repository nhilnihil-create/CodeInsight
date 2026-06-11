#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> s = a;
    sort(s.rbegin(), s.rend());
    rep(i, n) {
        int ans = s[0];
        if (s[0] == a[i])
            ans = s[1];
        cout << ans << endl;
    }
    return 0;
}