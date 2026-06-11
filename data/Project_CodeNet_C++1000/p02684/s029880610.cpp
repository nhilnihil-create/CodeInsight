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

    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }

    ll cyrange = 0, cycnt = 0, s = 0;
    vector<ll> seen(N, -1);
    seen[s] = 0;
    while (1) {
        cycnt++;
        s = A[s];
        if (seen[s] != -1) {
            cyrange = seen[s];
            cycnt -= cyrange;
            break;
        }
        seen[s] = cycnt;
    }

    ll amari;
    if (K - cyrange > 0) {
        K -= cyrange;
        amari = K % cycnt;
    } else {
        s = 0;
        amari = K;
    }

    while (amari != 0) {
        amari--;
        s = A[s];
    }

    cout << s + 1 << endl;
}