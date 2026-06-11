#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (a <= b) {
        rep(i, b) {
            ans *= 10;
            ans += a;
        }
    } else {
        rep(i, a) {
            ans *= 10;
            ans += b;
        }
    }
    printf("%d\n", ans);

    return 0;
}