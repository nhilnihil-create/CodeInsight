#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int N;
int x[10], y[10];
double dist(int i, int j) {
    double X = x[i] - x[j];
    double Y = y[i] - y[j];
    return pow(X * X + Y * Y , 0.5);
}
void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i];
    }
    double ans = 0.0;
    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            ans += dist(i, j) * 2 / N;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return;
}
int main() {
    solve();
    return 0;
}
