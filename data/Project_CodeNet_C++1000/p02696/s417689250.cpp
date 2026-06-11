#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, N;
    cin >> A >> B >> N;
    ll ans = 0;

    if (N >= B - 1) {
        ll i = B - 1;
        ll temp = (A * i) / B - A * (i / B);
        ans = temp;
    } else {
        ll temp = (A * N) / B - A * (N / B);
        ans = temp;
    }

    cout << ans << endl;
}