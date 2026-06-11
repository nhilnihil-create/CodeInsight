#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a;
    int ans = 0;
    rep(i, 3) {
        cin >> a;
        ans += a;
    }
    if (ans >= 22) cout << "bust" << endl;
    else cout << "win" << endl;
    return 0;
}