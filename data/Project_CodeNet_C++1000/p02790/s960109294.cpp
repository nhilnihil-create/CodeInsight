#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    string ans;
    rep(i, b) ans += a + '0';
    cout << ans << endl;
    return 0;
}