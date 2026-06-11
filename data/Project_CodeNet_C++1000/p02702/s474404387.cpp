#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    getline(cin, S);

    vector<int> modcounts(2019, 0);
    int premod = 0;
    int tensmod = 1;  // 10^0 % 2019
    for (int i = S.length() - 1; i >= 0; i--) {
        int c = S.at(i) - '0';
        int m = (c * tensmod + premod) % 2019;
        modcounts[m]++;
        tensmod = (tensmod * 10) % 2019;
        premod = m;
    }
    int64_t result = 0;
    for (uint m = 0; m < modcounts.size(); m++) {
        if (m == 0 && modcounts[m] >= 1) {
            result += (int64_t)(modcounts[m] + 1) * modcounts[m] / 2;
        } else if (modcounts[m] >= 2) {
            result += (int64_t)modcounts[m] * (modcounts[m] - 1) / 2;
        }
    }
    cout << result << endl;
}
