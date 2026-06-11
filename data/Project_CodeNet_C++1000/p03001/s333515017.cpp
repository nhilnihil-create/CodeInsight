#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll W, H, a, b;
int main() {
    cin >> W >> H >> a >> b;

    long double ans = (double)W * H / 2;

    bool judge = (W == 2 * a && H == 2 * b);

    printf("%.10Lf %d\n", ans, judge);
}