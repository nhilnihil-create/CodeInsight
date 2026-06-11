#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    string S;
    int n, k;
    cin >> n >> k >> S;
    vector<int> vec;
    int cnt = 1;
    rep (i, 1, n) {
        if (S[i - 1] != S[i]) {
            vec.push_back (cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    vec.push_back (cnt);
    int l = vec.size();
    if (l < 2 * k + 1) {
        cout << n - 1 << "\n";
        return 0;
    }
    //累積和
    int sum2 = 0;
    int s[l + 1] = {};
    rep (i, 0, l) {
        s[i + 1] = s[i] + vec[i];
        sum2 += vec[i] - 1;
    }
    //計算
    int ans = 0;
    rep (i, 0, n - 2 * k) {
        int sum;
        sum = s[i + 2 * k + 1] - s[i] - 1 + sum2 -
              (s[i + 2 * k + 1] - s[i] - k * 2 - 1);
        // cout << i << " " << sum << "\n";
        ans = max (ans, sum);
    }
    cout << ans << "\n";
}