#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

//const int MAXN = (int)1e5 + 5;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    sort(arr.rbegin(), arr.rend());
    long long ans = 0;
    for (int i = k; i < n; ++i) {
        ans += arr[i];
    }

    cout << ans << '\n';

    return 0;
}