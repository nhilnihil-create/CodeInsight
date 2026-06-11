#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

// O(n^2)
bool check(const string& s, int x) {
    int n = s.size();

    int cnt;
    rep(diff, x, n - x + 1) {
        cnt = 0;
        rep(i, 0, n - diff) {
            // (i, i + diff)
            if (s[i] == s[i + diff]) {
                ++cnt;
                if (cnt == x) { return true; }
            } else {
                cnt = 0;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ok = 0, ng = n / 2 + 1;
    while (ok + 1 != ng) {
        int mid = (ok + ng) / 2;
        if (check(s, mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;

    return 0;
}