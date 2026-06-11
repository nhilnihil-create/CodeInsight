#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 5e5 + 1, mod = 1e9 + 7;

using namespace std;

bool v[1001][1001];
int a[maxn], b[maxn];

signed main() {
    string s; cin >> s;
    int ans = 0, bal = 0, cl = 0, mbal = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '>') {
            ++cl;
            if (bal == 0) {ans += cl - (cl <= mbal); b[i - cl + 1 + (cl <= mbal)]++; b[i + 1]--;}
            else {b[i + 1] = -bal; bal = 0;}
        } else {
            cl = 0;
            b[i + 1] = 1;
            ans += (++bal);
            mbal = bal;
        }
    }
    cout << ans << '\n';
    return 0;
}
