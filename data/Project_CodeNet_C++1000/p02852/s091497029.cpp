#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> ans;
    int start = n;
    while (start) {
        int deme = m;
        while (deme) {
            //cout << deme << endl;
            if ((start - deme >= 0) && (s[start - deme] == '0')) {
                start -= deme;
                ans.push_back(deme);
                break;
            }
            if (deme == 1) {
                cout << -1 << endl;
                return 0;
            }
            deme--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}