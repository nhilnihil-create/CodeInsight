#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int prize[300];

int main() {
    prize[1] = 300000;
    prize[2] = 200000;
    prize[3] = 100000;
    int x, y;
    cin >> x >> y;
    int ans = prize[x] + prize[y];
    if (x == 1 && y == 1) ans += 400000;
    cout << ans << endl;
}