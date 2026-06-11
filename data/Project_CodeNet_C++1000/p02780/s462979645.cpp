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

    int n, k;
    cin >> n >> k;
    vector<double> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] = (arr[i] * (arr[i] + 1) / 2) / arr[i];
//        cout << arr[i] << ' ';
        if (i > 0)
            arr[i] += arr[i - 1];

    }

    double ans = arr[k - 1];
    for (int i = k; i < n; ++i) {
        ans = max(ans, arr[i] - arr[i - k]);
    }

    cout << ans << '\n';

    return 0;
}