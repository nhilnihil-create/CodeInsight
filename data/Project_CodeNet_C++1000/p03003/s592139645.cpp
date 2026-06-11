#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

LL dp[2005][2005];
LL sum[2005][2005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for(int i = 0; i < n; ++i) {
        cin >> s[i];

    }
    for(int i = 0; i < m; ++i) {
        cin >> t[i];

    }

    dp[0][0] = 1;
    sum[1][1] = 1;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            if(i == 0 && j == 0) continue;
            if(i - 1 >= 0 && j - 1 >= 0 && s[i - 1] == t[j - 1]) {
                dp[i][j] = sum[i][j];

            }
            sum[i + 1][j + 1] = (sum[i + 1][j] + sum[i][j + 1]) % MOD - sum[i][j] + dp[i][j];
            sum[i + 1][j + 1] = (sum[i + 1][j + 1] + MOD) % MOD;
        }
    }
    cout << sum[n + 1][m + 1] << endl;
    return 0;
}

