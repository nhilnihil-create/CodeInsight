#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    ll sum = 0;
    int p = 0, i = 0;
    char ch = '\0';
    for (char c : s) {
        if (ch != c) {
            if (ch == '>') sum += max(i, p), p = 0;
            else p = i;
            ch = c;
            i = 1;
        } else sum += i, i++;
    }

    sum += max(i, p);
    cout << sum;

    return 0;
}
