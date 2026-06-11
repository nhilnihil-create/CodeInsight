#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const int MOD = 1e9+7;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    ll k;
    cin >> k;   

    int n = s.length();

    ll res = 0;
    ll sum0 = 1;
    ll sum1 = 1;
    bool ok1 = true;
    rep(i, n - 1) {
        if (ok1) {
            if (s[i] == s[i + 1]) {
               sum0++;
               continue;
            }
            else {
                ok1 = false;
            }
        }

        if (s[i] == s[i + 1]) {
            sum1++;
            continue;
        }
        res += sum1 / 2;
        sum1 = 1;
    }
    
    res *= k;

    if (sum0 == n) {
        cout << sum0 * k / 2 << endl;
        return 0;
    }

    if (s[0] == s[n-1]) {
        res += sum0 / 2 + (sum0 + sum1) / 2 * (k - 1) + sum1 / 2;
    }
    else {
        res += (sum0 / 2 + sum1 / 2) * k;
    }

    cout << res << endl;

    return 0;
}