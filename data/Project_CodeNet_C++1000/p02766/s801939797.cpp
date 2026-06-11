#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    int64_t n, k; cin >> n >> k;
    int64_t ans = 1,digit = k;

    while(n>=digit) {
        digit *= k;
        ans++;
    }

    cout << ans << endl;
}