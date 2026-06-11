#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vi s(n + 1);
    rep(i, 0, n + 1) {
        char c;
        cin >> c;
        s[i] = c == '1' ? 0 : 1;
    }

    int curr = n;
    vi ans;

    // O(n)
    while (curr != 0) {
        // 到達可能な範囲．
        auto left = s.begin() + max(0, curr - m);
        auto right = s.begin() + curr;

        // 進行可能な範囲のうち，最も遠い点．
        int next = distance(s.begin(), find(left, right, 1));

        // 進行可能な点が無い場合．
        if (next == curr) { break; }

        ans.push_back(curr - next);
        curr = next;
    }

    if (curr != 0) {
        cout << -1 << endl;
    } else {
        reverse(all(ans));
        for (int a : ans) { cout << a << " "; }
        cout << endl;
    }

    return 0;
}