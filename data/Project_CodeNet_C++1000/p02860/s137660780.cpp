#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s, res = "No";
    cin >> n >> s;
    if (n % 2 == 0) {
        if (s.substr(0,n/2) == s.substr(n/2, n/2)) res = "Yes";
    }
    cout << res << endl;
}