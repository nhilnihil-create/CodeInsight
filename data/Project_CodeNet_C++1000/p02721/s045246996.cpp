#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define TEST(...)                                                              \
    { printf("! "), printf(__VA_ARGS__); }
#else
#define TEST(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
  public:
    int Max[maxn][30], lg[maxn];
    void solve() {
        int n, k, c;
        string s;
        cin >> n >> k >> c >> s;
        vector<int> p;
        int pos = 0;
        while (p.size() != k) {
            if (s[pos] == 'o') {
                p.push_back(pos);
                pos += c + 1;
            } else {
                pos++;
            }
        }
        lg[2] = 1;
        for (int i = 3; i < maxn; ++i)
            lg[i] = lg[i / 2] + 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'x')
                Max[i][0] = -1;
            else
                Max[i][0] = i;
        }
        for (int i = 1; i <= 20; ++i) {
            for (int j = 0; j + (1 << i) - 1 < n; ++j) {
                Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
            }
        }
        auto rmq = [&](int l, int r) {
            int s = lg[r - l + 1];
            return max(Max[l][s], Max[r + 1 - (1 << s)][s]);
        };
        vector<int> R(k), ans;
        R[k - 1] = rmq(p[k - 1], n - 1);
        if (R[k - 1] == p[k - 1])
            ans.push_back(p[k - 1]);
        for (int i = k - 2; i >= 0; --i) {
            R[i] = rmq(p[i], R[i + 1] - c - 1);
            if (R[i] == p[i])
                ans.push_back(p[i]);
        }
        sort(ans.begin(), ans.end());
        for (int i : ans)
            cout << i + 1 << " ";
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}