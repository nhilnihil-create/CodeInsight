#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll x;
    cin >> x;
    ll money = 100;
    int ans=0;
    while (x > money) {
        money += money/100;
        ans++;
    }
    cout << ans << endl;
    return 0;
}