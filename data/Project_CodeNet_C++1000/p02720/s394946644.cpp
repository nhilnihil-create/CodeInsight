#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    int n; cin >> n;
    vvll cnt(20, vll(10));
    vll sum(20);
    FOR(i, 0, 9)
        cnt[1][i] = 1;
    sum[1] = 9;
    FOR(i, 2, 11) FOR(j, 0, 9) {
        if (j > 0) cnt[i][j] += cnt[i - 1][j - 1];
        cnt[i][j] += cnt[i - 1][j];
        if (j + 1 <= 9) cnt[i][j] += cnt[i - 1][j + 1];
        if (j > 0) sum[i] += cnt[i][j];
    }
    int p = 1;
    while (n > sum[p])
        n -= sum[p++];
    int ls = 2;
    ROF(i, p, 1) {
        int c = max(0, ls - 1);
        // if (i == p) c = 1;
        // else c = 0;
        while (n > cnt[i][c]) {
            n -= cnt[i][c], c++;
        }
        cout << c;
        ls = c;
    }
    cout << endl;
}