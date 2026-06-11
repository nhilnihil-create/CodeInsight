#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll M = 1e9 + 7;
const int iinf = 1 << 29;
const long long llinf = 1ll << 60;
const double PI = 3.14159265;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll mrand(ll B) {
  return (ull)rng() % B;
}

int m[2][2019];

void work() {
    string s; cin>>s;
    int n = s.size();
    ll sum = 0, ans = 0;
    int cur = 0;
    m[cur][0] = 1;
    for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        sum = (sum + d) % 2019;
        ans += m[cur][sum];
        for (int j = 0; j < 2019; ++j) m[cur^1][j] = 0;
        for (int j = 0; j < 2019; ++j) {
            m[cur^1][(j*10)%2019] += m[cur][j];
        }
        sum = (sum * 10) % 2019;
        ++m[cur^1][sum];
        cur ^= 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int nt; cin>>nt; while (nt--) work();
    work();
    return 0;
}
