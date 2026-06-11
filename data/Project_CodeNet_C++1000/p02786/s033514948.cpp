#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

//const int MAXN = (int)1e5 + 5;

long long solve(long long x) {
    if (x == 1)
        return 1;
    return 2 * solve(x / 2) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    long long h;
    cin >> h;
    cout << solve(h) << '\n';

    return 0;
}