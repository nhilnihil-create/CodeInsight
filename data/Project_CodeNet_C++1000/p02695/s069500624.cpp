#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinations_with_replacement(vector<int> iterable, int r) {
    vector<vector<int>> ret;
    vector<int> temp(r);
    ret.push_back(temp);
    while (1) {
        int i;
        for (i = r - 1; i > -1; i--) {
            if (temp[i] != iterable.size() - 1) {
                break;
            }
            else if (i == 0) {
                return ret;
            }
        }
        int val = temp[i] + 1;
        for (int j = i; j < r; j++) {
            temp[j] = val;
        }
        ret.push_back(temp);
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> v(q);
    vector<vector<int>> ret;
    vector<int> temp(4);
    for (int i = 0; i < q; i++) {
        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        v[i] = temp;
    }

    vector<int> test(m);
    for (int i = 0; i < m; i++) {
        test[i] = i + 1;
    }

    ret = combinations_with_replacement(test, n);

    int tempAns = 0;
    int ans     = 0;
    for (auto tempA : ret) {
        tempAns = 0;
        for (int j = 0; j < q; j++) {
            if (tempA[v[j][1] - 1] - tempA[v[j][0] - 1] == v[j][2]) {
                tempAns += v[j][3];
            }
        }
        ans = max(ans, tempAns);
    }
    cout << ans << endl;
}