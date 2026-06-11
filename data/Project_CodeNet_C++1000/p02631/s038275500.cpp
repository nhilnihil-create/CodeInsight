#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    ll sum = 0;
    rep(i, n) sum ^= a[i];

    rep(i, n){
        ll s = sum ^ a[i];
        cout << s << endl;
    }

}