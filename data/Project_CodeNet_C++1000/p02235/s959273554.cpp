#include <bits/stdc++.h>
using namespace std;
const long long INF = 123456789;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i, r, n) for (ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i, r, n) for (ll i = (ll)(n - 1); i >= r; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<pair<ll, ll> > vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef list<ll> lst;

ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

#define Endl endl

/*--------------------template--------------------*/

ll dp[1006][1006] = { 0 };

int main()
{
    cin >> n;
    ll ma = 0;
    REP(i, n)
    {
        string t;
        cin >> s >> t;
        ma = 0;
        s = ' ' + s; //????????????????????????
        t = ' ' + t;
        FOR(i, 1, s.size())
        {
            dp[i][0] = 0;
        }
        FOR(i, 1, t.size())
        {
            dp[0][i] = 0;
        }
        FOR(i, 1, s.size())
        {
            FOR(j, 1, t.size())
            {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                ma = max(ma, dp[i][j]);
            }
        }
        cout << ma << Endl;
    }
}