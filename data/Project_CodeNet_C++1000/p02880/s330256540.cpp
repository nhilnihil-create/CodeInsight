#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string res = "No";
    Rep (i, 1, 10) {
        Rep (j, 1, 10) {
            if (i * j == n) res = "Yes";
        }
    }
    cout << res << endl;
}