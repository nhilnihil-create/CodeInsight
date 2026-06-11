#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> d;
int main() {
    cin >> N;
    d.resize(N);
    rep(i, N) cin >> d[i];

    sort(d.begin(), d.end());
    ll left = N / 2 - 1;
    ll right = N / 2;

    ll ans = d[right] - (d[left] + 1) + 1;
    cout << max(0LL, ans) << endl;
}