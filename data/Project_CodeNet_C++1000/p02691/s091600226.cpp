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

    int N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> ma;
    rep(i, N) {
        cin >> A[i];
        ma[i - A[i]]++;
    }

    ll ans = 0;
    rep(i, N) { ans += ma[A[i] + i]; }

    cout << ans << endl;
}