#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
auto chmin = [](auto&& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto chmax = [](auto&& a, auto b){ if (a < b) {a = b; return true;} return false; };
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
ll N, K;
ll a[200000];
ll ans = 0;
ll sum[200500];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++) {
        sum[i] = sum[i-1] + a[i-1];
    }
    for(int i = 0; i + K <= N; i++) {
        chmax(ans, sum[i+K] - sum[i]);
    }
    ans += K;
    cout << fixed << setprecision(20) << ans / 2.0;
    return 0;
}