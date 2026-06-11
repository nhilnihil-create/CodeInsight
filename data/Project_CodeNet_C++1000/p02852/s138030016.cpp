#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> ans;
    for(int i = n; i > 0; --i) {
        for(int j = i - m; j < i; ++j) {
            if(j <= 0) {
                ans.push_back(i);
                i = -1;
                break;
            } else if (s[j] == '0') {
                ans.push_back(i - j);
                i = j+1;
                break;
            }
            if(j == i-1 && s[i-1] == '1') {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    for(int i = ans.size()-1; i >= 0; --i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}