#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
const int mod = 1000000007;

int main() {
    double a, b, x, rad, ans;
    cin >> a >> b >> x;
    x = x / a;
    if(x > a * b / 2) {
        rad = atan(2 * (a * b - x) / (a * a));
    } else {
        rad = atan(b * b / (2 * x));
    }
    ans = rad * 180 / M_PI;
    printf("%.10f\n", ans);
    return 0;
}