#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // 逆順
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    int cur = N;
    vector<int> ans;
    while (cur) {
        bool flag = false;
        for (int i = M; i >= 1; i--) {
            if (cur-i>=0 && S[cur-i] == '0') {
                cur -= i;
                flag = true;
                ans.push_back(i);
                break;
            }
        }
        if (!flag) {
            cout << -1 << '\n';
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    show(ans);
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}