#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<int> Div(int n) {
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);

            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    LL dp[SIZE][2];
    for(int i = 0; i < s.length(); ++i) {
        int l = s[i] - '0';

        if(i == 0) {
            dp[i][1] = 2;
            dp[i][0] = 1;

        } else {
            dp[i][0] = dp[i - 1][0] * 3 % MOD;
            if(l == 1) {
                dp[i][0] += dp[i - 1][1];
                dp[i][0] %= MOD;

            }

            if(l == 0) {
                dp[i][1] = dp[i - 1][1];

            } else {
                dp[i][1] = dp[i - 1][1] * 2 % MOD;

            }
        }
    }
    cout << (dp[s.length() - 1][0] + dp[s.length() - 1][1]) % MOD << endl;
    return 0;
}

