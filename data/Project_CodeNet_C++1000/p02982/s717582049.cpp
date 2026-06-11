#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    int x[n][d];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> x[i][j];
        }
    }

    int sum, cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            sum = 0;
            for (int k = 0; k < d; k++) {
                sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            for (int k = 0; k <= sum; k++) {
                if (k * k == sum) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
