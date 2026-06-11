#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
int main(void)
{
    int n;
    cin >> n;
    long double ans = ((n + 1) / 2) / double(n);
    cout << fixed << setprecision(15);
    cout << ans << endl;
}