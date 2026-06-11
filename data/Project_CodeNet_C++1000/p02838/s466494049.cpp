#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    ll zero[65] = {}, one[65] = {}; //桁ごとの数を数える
    ll ans = 0;
    rep (i, 0, n) {
        ll a;
        cin >> a;
        bitset<60> a_bit (a);
        rep (j, 0, 60) {
            if (a_bit[j]) one[j]++;
            else {
                zero[j]++;
            }
        }
    }
    ll sum = 1;
    const ll mod = 1e9 + 7;
    rep (i, 0, 60) {
        ans = (ans + (one[i] * zero[i]) % mod * sum % mod) % mod;
        sum = sum * 2 % mod;
        // cout << i << " " << one[i] << "\n";
    }
    cout << ans << "\n";
}