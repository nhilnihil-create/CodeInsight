#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<double> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());

    double ans = v.at(0);
    for (int i = 1; i < N; i++) {
        ans = (ans + v.at(i)) / 2;
    }
    cout << fixed << setprecision(8);
    cout << ans << endl;
}