#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
        ll n, k;
        cin >> n >> k;
        ll x, ans;
        x = n % k;
        if(x == 0)ans = 0;
        else if(abs(x-k) < abs(x))ans = abs(x-k);
        else ans = abs(x);
        cout << ans << endl;
        return 0;
}