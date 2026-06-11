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
    ll sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }

    ll ave1 = sum / N, ave2 = sum / N + 1, ave3 = sum / N - 1;
    ll tmp1 = 0, tmp2 = 0, tmp3 = 0;
    rep(i, N) {
        tmp1 += (A[i] - ave1) * (A[i] - ave1);
        tmp2 += (A[i] - ave2) * (A[i] - ave2);
        tmp3 += (A[i] - ave3) * (A[i] - ave3);
    }

    cout << min(tmp1, min(tmp2, tmp3)) << endl;

    return 0;
}