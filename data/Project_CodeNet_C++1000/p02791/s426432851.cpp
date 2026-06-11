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
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    int ans = 0;
    int mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < mn) {
            ++ans;
            mn = arr[i];
        }
    }

    cout << ans << '\n';

    return 0;
}