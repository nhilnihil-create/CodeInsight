#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> v(q);

    vector<int> temp(4);
    for (int i = 0; i < q; i++) {
        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        v[i] = temp;
    }

    vector<int> flgv(m + n - 1);
    vector<int> tempA(n);
    int cntflg  = 0;
    int cnt     = 0;
    int index   = 0;
    int tempAns = 0;
    int ans     = 0;
    for (int i = 0; i < pow(2, m + n - 1); i++) {
        cntflg = 0;
        for (int j = 0; j < m + n - 1; j++) {
            flgv[j] = 0;
            if (i >> j & 1) {
                flgv[j] = 1;
                cntflg++;
            }
        }
        if (cntflg == m - 1) {
            cnt   = 0;
            index = 0;
            for (int j = 0; j < m + n - 1; j++) {
                if (flgv[j] == 0) {
                    tempA[index] = cnt;
                    index++;
                }
                else {
                    cnt++;
                }
            }
            tempAns = 0;
            for (int j = 0; j < q; j++) {
                if (tempA[v[j][1] - 1] - tempA[v[j][0] - 1] == v[j][2]) {
                    tempAns += v[j][3];
                }
            }
            ans = max(ans, tempAns);
        }
    }
    cout << ans << endl;

    return 0;
}