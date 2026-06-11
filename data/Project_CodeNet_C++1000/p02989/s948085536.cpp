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
    vector<ll> d(N);

    rep(i, N) { cin >> d[i]; }

    sort(all(d));
    ll left = d[N / 2 - 1], right = d[N / 2];

    cout << right - left << endl;
}