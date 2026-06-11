#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

#define int long long
#define ll long long
#define double long double
#define pii pair<int, int>
#define vec vector
#define u_map unordered_map
#define u_set unordered_set
#define str string
#define all(el) el.begin(), el.end()
#define allr(el) el.rbegin(), el.rend()
#define sz(el) (int)el.size()
#define f first
#define s second
#define pb push_back
#define in insert
#define mp make_pair
#define endl "\n"
#define forn(i, n) for (int i = 0; i < n; ++i)

inline int maxi(int &a, int b) { if (b > a) { a = b; return 1; } return 0; }

inline int mini(int &a, int b) { if (b < a) { a = b; return 1; } return 0; }

inline int maxi(double &a, double b) { if (b > a) { a = b; return 1; } return 0; }

inline int mini(double &a, double b) { if (b < a) { a = b; return 1; } return 0; }

signed main() {

    int n;
    str S;
    cin >> n >> S;

    int ans = 0;
    for (int st = 0; st < n; st++) {
        int left = 0, right = 0;
        vec<int> z(n - st);
        str s = S.substr(st);
        for (int i = 1; i < sz(s); i++) {
            z[i] = max(0LL, min(right - i, z[i - left]));
            if (i >= right || i + z[i] >= right) {
                while (i + z[i] < sz(s) && s[i + z[i]] == s[z[i]]) {
                    z[i]++;
                }
                if (maxi(right, i + z[i])) {
                    left = i;
                }
            }
        }
        for (int i = 0; i < sz(z); i++) {
            maxi(ans, min(z[i], i));
        }
    }

    cout << ans;
    return 0;
}