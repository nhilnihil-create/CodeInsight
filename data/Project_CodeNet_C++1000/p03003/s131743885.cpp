#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;
const int mod = 1000000007;
int add(int a, int b) { return (a += b) < mod? a : a - mod; }
int sub(int a, int b) { return (a -= b) >=  0? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
void adds(int& a, int b) { a = add(a, b); }
void subs(int& a, int b) { a = sub(a, b); }
void muls(int& a, int b) { a = mul(a, b); }
void maxs(int& a, int b) { a = max(a, b); }
void mins(int& a, int b) { a = min(a, b); }
int pwr(int a, ll p) {
    if (p == 0) return 1;
    if (p & 1) return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

int n, m, s[2000], t[2000], dp[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < m; ++i)
        cin >> t[i];

    for (int j = m - 1; j >= 0; --j)
    {
        int dq = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            dp[i][j] = dp[i][j + 1];
            if (s[i] == t[j])
            {
                adds(dp[i][j], 1);
                adds(dp[i][j], dq);
            }
            adds(dq, dp[i][j + 1]);
        }
    }
    int sol = 1;
    for (int i = 0; i < n; ++i)
        adds(sol, dp[i][0]);
    cout << sol;
}
