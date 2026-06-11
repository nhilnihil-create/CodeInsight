#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define lll __int128
#define lp(i, a, b) for (int i = a; i < b; i++)
#define vec(v, type, sz) vector<type> v(sz)
#define in(v) \
    for (auto &i : v) cin >> i
#define all(v) v.begin(), v.end()
#define prv(v)                         \
    for (auto i : v) cout << i << " "; \
    cout << "\n"
#define MOD 1000000007
#define INF 1000000000
#define INFL 1000000000000000000ll
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vi vector<int>
#define vl vector<ll>
#define vii(v, n, m, val) vector<vector<int>> v(n, vector<int>(m, val))
#define viii(v, i, j, k, val)        \
    vector<vector<vector<int>>> v(i, \
                                  vector<vector<int>>(j, vector<int>(k, val)))
#define pii pair<int, int>
#define pb push_back
#define file_io                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main() {
    fast_io;
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    int pos = 0;
    vi l(k), r(k);
    int day = 0;
    while (pos < n && day < k) {
        if (s[pos] == 'o') {
            l[day++] = pos;
            pos += c;
        }
        pos++;
    }
    pos = n - 1;
    day = k - 1;
    while (pos >= 0 && day >= 0) {
        if (s[pos] == 'o') {
            r[day--] = pos;
            pos -= c;
        }
        pos--;
    }
    lp(i, 0, k) if (l[i] == r[i]) cout << l[i]+1 << "\n";
}