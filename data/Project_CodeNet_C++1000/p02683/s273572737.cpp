#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int n, m, x;
    long long Min = 999999999;

    cin >> n >> m >> x;
    vector<long long> kin(n);
    vector<vector<int>> data(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        cin >> kin.at(i);
        for (int j = 0; j < m; j++) cin >> data.at(i).at(j);
    }

    for (int bit = 0; bit < (1 << n); bit++) {
        long long tmpMin = 0;
        vector<int> sumRikai(m, 0);
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                tmpMin += kin.at(i);
                for (int j = 0; j < m; j++) sumRikai.at(j) += data.at(i).at(j);
            }
        }

        bool chk = true;
        for (int i = 0; i < m; i++) {
            if (sumRikai.at(i) < x) {
                chk = false;
                break;
            }
        }
        if (chk == true) Min = min(Min, tmpMin);
    }

    if (Min == 999999999) cout << -1;
    else cout <<Min;

    //
}