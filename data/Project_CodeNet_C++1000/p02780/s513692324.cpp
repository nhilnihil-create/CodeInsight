#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    int p[N];
    for (int i = 0; i < N; i++) cin >> p[i];
    double ans = 0.0, exp = 0.0;
    for (int i = 0; i < N; i++) {
        exp += (p[i] + 1) / 2.0;
        if (i < K-1) continue;
        ans = max(ans, exp);
        exp -= (p[i-K+1] + 1) / 2.0; 
    }
    cout << fixed << setprecision(10) << ans << endl;
}