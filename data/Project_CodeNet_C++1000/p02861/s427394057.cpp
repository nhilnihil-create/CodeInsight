#include <bits/stdc++.h>
using namespace std;

// const long long int MOD = 1000000007;
const int MOD = 1000000007;


int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    double ans = 0.0;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            double dist_ij = sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2));
            ans += dist_ij*2/N;
        }
    }
    // printf("%.6d\n", ans);
    cout << fixed << setprecision(7) << ans << endl;
}
