#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    ll cnt = 0;
    for (ll i = 1; i <= N; i++) {
        ll ma = (N - 1) / i;
        cnt += ma;
    }

    cout << cnt << endl;
}