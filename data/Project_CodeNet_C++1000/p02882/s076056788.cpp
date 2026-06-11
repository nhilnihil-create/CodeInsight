#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a, b, x;
    cin >> a >> b >> x;

    x /= a;

    double p=3.14159265358979;



    double ans = atan2(0.5 * a * a, (a * b - x));

    if(ans<atan2(a, b)){
        ans = 0.5*p-atan2(2 * x, b * b);
    } else {
        ans = 0.5 * p - ans;
    }

    ans = ans * 180.0 / p;
    printf("%.9lf\n", ans);
}