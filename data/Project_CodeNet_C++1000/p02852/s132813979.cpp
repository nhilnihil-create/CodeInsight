#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    string s; cin >> s;
    
    vector<int> v;
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 1;
        while (s[i] == '1') i--, cnt++;
        v.push_back(cnt);
    }

    vector<int> ans;
    int num = 0;
    for (auto &e: v) {
        if (e > m) {
            cout << -1 << endl;
            return 0;
        }

        if (num + e > m) {
            ans.push_back(num);
            num = e;
        } else {
            num += e;
        }
    }
    ans.push_back(num);
    for (int i = (int)ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " \n"[i == 0];
    }
    return 0;
}
