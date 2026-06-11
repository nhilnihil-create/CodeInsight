#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;
const double PI = acos(-1.0);

ll cal(int n, int times) {
    ll res = 1;
    for(int i = 0; i < times; ++i) {
        res = (res * n) % mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    ll ans = (cal(10, n) - cal(9, n) - cal(9, n) + cal(8, n)) % mod;

    ans = (ans+mod) % mod;
    cout << ans << endl;

}
