#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

ll N, K;
vector<ll> A(200010), F(200010);
bool isOK(ll key, ll cnt) {
    rep(i, N) {
        if (A[i] * F[i] > key) {
            cnt += (A[i] - key / F[i]);
        }
    }

    if (cnt <= K)
        return true;
    else
        return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    A.resize(N), F.resize(N);
    rep(i, N) { cin >> A[i]; }
    rep(i, N) { cin >> F[i]; }

    sort(all(A));
    sort(all(F), greater<ll>());

    ll ng = -1, ok = pow(10, 12) + 5;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid, 0))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;
}