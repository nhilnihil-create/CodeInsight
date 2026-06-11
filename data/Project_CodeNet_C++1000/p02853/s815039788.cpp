#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
ll p[1000];

int main(){
    ll ans = 0;
    int x, y;
    cin >> x >> y;

    p[1] = 300000;
    p[2] = 200000;
    p[3] = 100000;

    ans += p[x] + p[y];
    if (x == 1 && y == 1) ans += 400000;
    cout << ans << endl;
    return 0;
}