#include <bits/stdc++.h>

using namespace std;


int main() {
    int n,d;
    cin >> n >> d;
    vector<vector<int>> x(n,vector<int>(d));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < d; j++) {
            cin >> x[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            int counter = 0;
            for(int k = 0; k < d; k++) {
                int diff = abs(x[i][k] - x[j][k]);
                counter += diff * diff;
            }
            bool ok = false;
            for(int k = 0; k < 1000; k++) {
                if(k * k == counter) {
                    ok = true;
                }
            }
            if(ok) {
                ans++;
            }
        }
    }
    cout << ans / 2 << "\n";
    return 0;
}