#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int INF = 1001001001;
const double PI = acos(-1);

#define rep(i, n)  for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    rep(i, n) sum += a[i];
    ll ansSum = 0;
    ll ans = sum;
    rep(i, n) {
        ansSum += a[i];
        sum -= a[i];
        ans = min(ans, abs(sum-ansSum));
    }

    cout << ans << endl;
}
