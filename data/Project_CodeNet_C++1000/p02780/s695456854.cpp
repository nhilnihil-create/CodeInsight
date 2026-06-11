#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int n, k;
    double sum = 0;
    double ans = 0;
    cin >> n >> k;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    vector <double> s(n + 1);
    for (int i = 1; i <= n; i++) {
        sum += (1 + p.at(i - 1)) / 2;
        s.at(i) = sum;
    }
    for (int i = 0; i < n - k + 1; i++) {
        ans = max(ans, s.at(i + k) - s.at(i));
    }
    cout << fixed << setprecision(12) << ans << endl;

}