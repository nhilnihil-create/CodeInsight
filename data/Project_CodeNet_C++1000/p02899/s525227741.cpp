#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pll> A(N);
    rep(i, N) {
        ll a;
        cin >> a;
        A[i] = {a, i + 1};
    }

    sort(all(A));
    rep(i, N) { cout << A[i].second << " "; }
}