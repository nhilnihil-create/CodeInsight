#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n, m;
    cin >> n >> m;
    int s[m], c[m];
    rep(i, m) {
        cin >> s[i] >> c[i];
    }
    int ans = -1;
    rep(i, 1000) {
        string str = to_string(i);
        if (str.size() != n) continue;
        bool flag = true;
        rep(i, m) {
            if (str[s[i]-1]-'0' != c[i]) {
                flag = false;
            }
        }
        if (flag) {
            ans = stoi(str);
            break;
        }
    }
    cout << ans << endl;
}