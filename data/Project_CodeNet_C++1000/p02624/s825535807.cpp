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
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> en(N + 5, 1);
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            en[j]++;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += i * en[i];
    }

    cout << ans << endl;
}