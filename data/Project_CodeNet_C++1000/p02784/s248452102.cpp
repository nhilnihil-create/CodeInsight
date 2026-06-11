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

    int H, N;
    cin >> H >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    ll sum = accumulate(all(A), (ll)0);
    if (sum >= H) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}