#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
double sum, a;
int n;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        sum += 1.0 / a;
    }
    sum = 1.0 / sum;
    cout << fixed << setprecision(10) << sum;
    PLEC
}
