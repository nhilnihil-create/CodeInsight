// ABC179C.cpp

#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
int main()
{
    int n;
    cin >> n;

    int ans = 0;
    // (n+a-1)/aを求めて、bの個数は(n+a-1)-1となる
    for (int a = 1; a <= n; a++) {
        int add = (n + a - 1) / a - 1;
        ans += add;
    }
    cout << ans << endl;
}
