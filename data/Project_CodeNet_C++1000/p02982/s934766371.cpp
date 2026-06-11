#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<double>> p(n, vector<double>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> p[i][j];
        } 
    }

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {

            double temp = 0;
            for (int k = 0; k < d; k++) {
                temp += (p[i][k]-p[j][k])*(p[i][k]-p[j][k]);
            }
            double dist = sqrt(temp);
            if (modf(dist, &temp) == 0) {
                ans++;
            }
        } 
    }

    cout << ans << endl;
}