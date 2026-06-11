#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n, m;
    cin >> n >> m;
    vector<map<string, int>> score(n);
    rep(i, m) {
        int p;
        cin >> p;
        p--; // 0-index
        string word;
        cin >> word;
        if(word == "AC") {
            score[p]["AC"] = 1;
        } else {
            if (score[p]["AC"] != 1) score[p]["WA"]++;
        }
    }

    rep(i, n) {
        if (score[i]["AC"] == 0) score[i]["WA"] = 0;
    }

    map<string, int> ans;
    rep(i, n) {
        ans["AC"] += score[i]["AC"];
        ans["WA"] += score[i]["WA"];
    }

    cout << ans.at("AC") << " " << ans.at("WA") << endl;

    return 0;
}
