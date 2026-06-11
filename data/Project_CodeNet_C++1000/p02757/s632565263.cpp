#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

vector<ll> cnt(10000);

int main() {
    int n, p; cin >> n >> p;
    string S; cin >> S;
    ll ans = 0;
    if (p == 2 || p == 5) {
        for (int i = n - 1; i >= 0; i--) {
            if ((S[i] - '0') % p == 0) {
                ans += i + 1;
            }
        }
    } else {
        cnt[0] = 1;
        int rem = 0; int q = 1;
        for (int i = n - 1; i >= 0; i--) {
            rem = (rem + (q * (S[i] - '0'))) % p;
            cnt[rem]++;
            q = (10 * q) % p;
        }
        for (auto m : cnt) {
            ans += m * (m - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}