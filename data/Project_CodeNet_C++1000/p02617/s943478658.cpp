#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979
#endif
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
    ll i, j, k;
    ll N;
    cin >> N;
    ll v_all = 0;
    for(i = 1; i <= N; i++) {
        v_all += i * (N - i + 1);
    }
    ll e_all = 0;
    for(i = 0; i < N - 1; i++) {
        ll u, v;
        cin >> u >> v;
        e_all += min(u, v) * (N - max(u, v) + 1);
    }
    cout << v_all - e_all << endl;

    return 0;
}
