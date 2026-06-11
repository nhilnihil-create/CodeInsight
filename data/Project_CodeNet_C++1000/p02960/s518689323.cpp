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

int dp[SIZE][13];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i) {
        int d = s[i] - '0';
        if(i == 0) {
            if(s[i] == '?') {
                for(int j = 0; j < 10; ++j) {
                    dp[i][j] = 1;

                }
            } else {
                dp[i][d] = 1;

            }
        } else {
            if(s[i] == '?') {
                for(int j = 0; j < 13; ++j) {
                    for(int k = 0; k < 10; ++k) {
                        dp[i][(j * 10 + k) % 13] = (dp[i][(j * 10 + k) % 13] + dp[i - 1][j]) % MOD;

                    }
                }
            } else {
                for(int j = 0; j < 13; ++j) {
                    dp[i][(j * 10 + d) % 13] = (dp[i][(j * 10 + d) % 13] + dp[i - 1][j]) % MOD;

                }
            }
        }
    }
    cout << dp[s.size() - 1][5] << endl;

    return 0;
}

