#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int q;
    cin >> q;
    for (int l = 0; l < q; ++l) {
        int m;
        cin >> m;

        vector<bool> dp(m + 1);
        for (int i : v) {
            vector<int> pos;
            for (int j = 0; j < dp.size(); ++j) {
                if (dp[j]) {
                    pos.push_back(j);
                    pos.push_back(j + i);
                }
                else if (i == j) {
                    pos.push_back(j);
                }
            }
            dp = vector<bool>(m + 1);
            for (int j : pos) {
                if (j < dp.size()) {
                    dp[j] = true;
                }
            }
        }

        if (dp[m]) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}