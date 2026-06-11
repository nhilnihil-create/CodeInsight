#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double n;
    cin >> n;
    double odd = (int)n/2;
    if ((int)n%2==1) odd++;
    cout << fixed << setprecision(9) << odd/n << '\n';
}
/*

 */