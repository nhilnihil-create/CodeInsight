#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> vec(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        cin >> vec.at(i).at(0);
        for (int j = 1; j <= m; j++) cin >> vec.at(i).at(j);
    }
    int casemoney, ans = 1200000;
    vector<int> eachsum;
    bool tf = false, casetf;
    for (int bit = 0; bit < (1 << n); bit++) {
        casemoney = 0;
        eachsum = vector<int>(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            if(bit & (1 << (i-1))){
                casemoney += vec.at(i).at(0);
                for (int j = 1; j <= m; j++) eachsum.at(j) += vec.at(i).at(j);
            }
        }
        casetf = true;
        for(int j = 1; j <= m; j++) {
            if(eachsum.at(j) >= x) continue;
            else {
                casetf = false;
                break;
            }
        }
        if(casetf) {
            tf = true;
            ans = min(ans, casemoney);
        }
    }

    if (tf) cout << ans << endl;
    else cout << -1 << endl;
}