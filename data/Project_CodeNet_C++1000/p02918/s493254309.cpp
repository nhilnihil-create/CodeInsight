#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};
fastio _fast_io;

const int N = 1e5 + 5;
int n, k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    int res = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            ++res;
    }
    res = min(res + k * 2, n - 1);
    cout << res << endl;
    return 0;
}
