#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll h;
    cin >> h;
    int keta = 0;
    while (1) {
        h /= 2;
        keta++;
        if (h == 0) break;
    }
    ll ans = pow(2, keta) - 1;
    cout << ans << endl;
    return 0;
}