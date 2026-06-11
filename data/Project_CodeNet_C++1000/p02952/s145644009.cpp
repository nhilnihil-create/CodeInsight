#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool odd(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    if (cnt % 2 == 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (odd(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}