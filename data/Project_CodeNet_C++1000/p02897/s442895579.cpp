#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    double ans = 0.5;
    if (n % 2) {
        ans = (n / 2 + 1) / (double)n;
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}