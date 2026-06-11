#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    int N; cin >> N;
    vector<double> v(N, 0.0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    long double ans = (v[0] + v[1]) / 2.0;
    for (int i = 2; i < N; ++i) ans = (ans + v[i]) / 2.0;
    cout << fixed << setprecision(10) << ans << endl;
}
