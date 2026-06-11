#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int c = n;
    vector<int> ans;
    while (c > 0) {
        bool ok = false;
        // cerr << c << endl;
        for (int i = m; i > 0; --i) {
            // cerr << "[!]" << i << " " << c << " " << s[c-i] << endl;
            if (c-i < 0) continue;
            if (s[c-i] == '1') continue;
            ok = true;
            c = c-i;
            ans.push_back(i);
            break;
        }
        if (!ok) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[ans.size()-1-i] << " ";
    }
    cout << endl;
}
