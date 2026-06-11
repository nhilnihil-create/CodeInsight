#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

int main() {
    double L;
    cin >> L;
    double res=L/3;
    cout << fixed << setprecision(6) << res*res*res;
    return 0;
}