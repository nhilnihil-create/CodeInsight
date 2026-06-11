#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    int res = 1;
    Rep (i, 1, n) {
        if (s[i] != s[i-1]) res++;
    }
    cout << res << endl;
}