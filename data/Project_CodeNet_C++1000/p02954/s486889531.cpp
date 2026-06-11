#include <bits/stdc++.h>
#define rep(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define repr(i, n, m) for (int i = (int)(n) - 1; i >= (int)(m); i--)
using namespace std;
using ll = int64_t;
const int MOD = 1000000007; // 10^9+7

//https://atcoder.jp/contests/abc136/tasks/abc136_d

int main() {
    string s;
    cin >> s;
    vector<int> n(1, 0);
    int cnt = 1;
    rep(i, 0, s.size() - 1) {
        if (s[i] == s[i + 1]) {
            cnt++;
        } else {
            n.push_back(cnt);
            cnt = 1;
        }
    }
    n.push_back(cnt);

    vector<int> ans(s.size(), 0);
    int ridx = -1;
    int lidx = 0;
    rep(i, 1, n.size() - 1)
    {
        if (i % 2 == 1) {
            ridx += n[i] + n[i - 1];
            lidx += n[i] + n[i - 1];
            ans[ridx] += (n[i]  + 1) / 2;
            ans[lidx] += n[i] / 2;
            ans[ridx] += n[i + 1] / 2;
            ans[lidx] += (n[i + 1] + 1) / 2;
        }
    }

    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

}
