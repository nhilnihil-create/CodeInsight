#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int inf = ~0u >> 1;
typedef pair<int, int> P;
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n)-1; i >= a; --i)
const ll mod = 1e9 + 7;
int main() {
    IO;
    string s, t;
    cin >> s >> t;
    int ls = s.length(), lt = t.length();
    int ans = inf;
    REP(i, 0, ls - lt + 1) {
        int sum = 0;
        REP(j, 0, lt) {
            if (s[i + j] != t[j]) {
                sum++;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

