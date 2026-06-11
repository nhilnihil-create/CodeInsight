#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    double a, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += 1 / a;
    }
    cout << setprecision(20) << 1 / sum << endl;
    return 0;
}