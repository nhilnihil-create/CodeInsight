#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> dp(1e4+1);

    for (int i=1; i<101; i++) {
        for (int j=1; j<101; j++) {
            for (int k=1; k<101; k++) {
                int duh = i*i + j*j + k*k + i*j + j*k + k*i;
                if (duh < 1e4+1) {
                    dp[duh]++;
                }
            }
        }
    }
    int n;
    cin >> n;
    for (int i=1; i<n+1; i++) cout << dp[i] << " ";
    cout << "\n";
}
