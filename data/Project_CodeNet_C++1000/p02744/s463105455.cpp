#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
set<string> ans;

void dfs(int cnt, string s = "", char max_c = 'a') {
    if (cnt == N - 1) {
        // cout << cnt << endl;
        // cout << s << endl;
        ans.insert(s);
        return;
    } 

    // s の最後の1文字から1文字後
    // int last = s[s.size() - 1] - 'a';
    int last = max_c - 'a';
    for (int k = 0; k <= last + 1; k++) {
        string target = s;
        target.push_back('a' + k);
        if (max_c < ('a' + k)) {
            dfs(cnt + 1, target, 'a' + k);
        } else {
            dfs(cnt + 1, target, max_c);
        }
    }
}

int main() {
    cin >> N;
    dfs(0, "a");

    for (auto s : ans) {
        cout << s << endl;
    }
}