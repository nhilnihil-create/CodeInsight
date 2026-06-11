#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int N;
    cin >> N;
    vector<ld> v(N);
    rep(i, N) { cin >> v[i]; }

    sort(all(v));
    ld ans = (v[0] + v[1]) / 2;
    for (int i = 2; i < N; i++) {
        ans = (ans + v[i]) / 2;
    }

    cout << fixed << setprecision(10) << ans << endl;
}