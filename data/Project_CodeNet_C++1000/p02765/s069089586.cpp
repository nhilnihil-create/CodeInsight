#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, r;
    cin >> n >> r;
    int ans = 0;
    if (n >= 10)
        ans = r;
    else
        ans = 100 * (10 - n) + r;
    cout << ans << endl;
    return 0;
}