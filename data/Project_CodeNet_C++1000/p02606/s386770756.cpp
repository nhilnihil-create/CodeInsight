#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll L, R, d;
    cin >> L >> R >> d;
    ll ans = 0;
    for (int i = L; i <= R; ++i) {
        if (i % d == 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
