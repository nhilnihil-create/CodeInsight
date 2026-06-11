#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    if (k > 0) {
        ans += min(k, a);
        k-=a;
    }
    if (k > 0) {
        k-=b;
    }
    if (k > 0) {
        ans-=min(k, c);
        k-=c;
    }
    cout << ans << endl;
    return 0;
}