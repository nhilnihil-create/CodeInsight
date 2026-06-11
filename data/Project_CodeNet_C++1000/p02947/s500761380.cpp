#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    map<string, ll> a;
    rep(i, n) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (a[s] >= 1)
            ans += a[s];
        a[s]++;
    }

    cout << ans << endl;
    return 0;
}