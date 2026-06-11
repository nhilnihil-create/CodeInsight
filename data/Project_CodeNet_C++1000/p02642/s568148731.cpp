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

    int N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> m;
    rep(i, N) {
        cin >> A[i];
        m[A[i]]++;
    }

    sort(all(A));
    ll ma = A[N - 1];
    ll ans = 0;
    vector<bool> div(ma + 5, false);
    rep(i, N) {
        if (!div[A[i]] && m[A[i]] == 1)
            ans++;
        for (int j = A[i]; j < ma + 5; j += A[i]) {
            div[j] = true;
        }
    }

    cout << ans << endl;

    return 0;
}
