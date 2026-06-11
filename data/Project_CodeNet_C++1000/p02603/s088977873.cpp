#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll stock = 0, money = 1000;
    rep(i, n) {
        // 購入
        {
            ll mv = a[i];
            bool exchange = false;
            reps(j, i + 1, n) {
                mv = min(mv, a[j]);
                if (a[j] > a[i]) {
                    exchange = true;
                    break;
                }
            }
            if ((exchange) && (mv == a[i])) {
                ll cnt = money / a[i];
                stock += cnt;
                money -= cnt * a[i];
            }
        }
        // 売却
        {
            ll mv = a[i];
            reps(j, i + 1, n) {
                mv = max(mv, a[j]);
                if (a[j] < a[i]) break;
            }
            if (mv == a[i]) {
                money += stock * a[i];
                stock = 0;
            }
        }
    }
    cout << money << endl;
    return 0;
}
