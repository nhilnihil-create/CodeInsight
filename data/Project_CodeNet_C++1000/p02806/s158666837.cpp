#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    vector<int> t(n);
    rep(i, n) {
        cin >> s.at(i);
        cin >> t.at(i);
    }

    string x; cin >> x;
    bool flg = false;
    int ans = 0;
    rep(i, n) {
        if (flg == false && x == s.at(i)) {
            flg = true;
            continue;
        }

        if (flg == true) {
            ans += t.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}