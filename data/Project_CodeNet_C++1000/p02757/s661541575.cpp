#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if (10 % p == 0) {
        ll ans = 0;
        rep(r, n) {
            if ((s[r] - '0') % p == 0) {
                ans += r + 1;
            }
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> d(n + 1);
    int ten = 1;
    for (int i = n - 1; i >= 0; --i) {
        int a = (s[i] - '0') * ten % p;
        d[i] += (d[i+1] + a) % p;
        ten *= 10;
        ten %= p;
    }

    vector<int> cnt(p);
    ll ans = 0;
    // iを左端の桁としたときに、右側に選べる物が何個あるかをカウントしながら追加している
    for (int i = n; i >= 0; --i) {
        ans += cnt[d[i]];
        cnt[d[i]]++;
    }
    cout << ans << endl;

    return 0;
}