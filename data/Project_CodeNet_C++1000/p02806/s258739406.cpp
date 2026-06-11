#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double eps = 0.00001;
const int MOD = 1000000007;
const int INF = 2147480555;
const ll LINF = 2223372000000000555;
const int N = 1550555;
const int M = 525;

string s[N];
int t[N];
void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> s[i] >> t[i];
    }

    string str;
    cin >> str;

    bool ok = false;
    ll sum = 0;
    for (int i = 1; i <= n; i++){
        if (ok) sum += t[i];
        if (s[i] == str) ok = true;
    }

    cout << sum;

}


int main() {
    ios_base::sync_with_stdio(false);
#ifdef dddxxz
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else

#endif

    int T = 1;
    //cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}