#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    double theta;
    if (2 * x < a * a * b) {
        theta = atan(a * b * b / (2.0 * x)) * 180 / acos(-1);
    } else {
        theta = atan(2.0 * (a * a * b - x) / (a * a * a)) * 180 / acos(-1);
    }
    cout << setprecision(20) << theta << endl;
    return 0;
}