#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define log_2(a) (log((a)) / log(2))
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = 1e9;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 105;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    int cnt[SIZE][SIZE] = {};
    int mp[SIZE][SIZE] = {};
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            char c;
            cin >> c;
            if(c == '#') mp[i][j] = 1;
            cnt[i][j] = INF;
        }
    }

    cnt[1][1] = 0;
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            if(mp[i][j] == 1) {
                cnt[i][j] = 1;
            } else {
                cnt[i][j] = 0;
            }
            if(i == 1 && j == 1) {
                continue;
            }
            if(i == 1) {
                cnt[i][j] += cnt[i][j - 1];
                if(mp[i][j - 1] + mp[i][j] == 2) {
                    cnt[i][j]--;
                }
            } else if(j == 1) {
                cnt[i][j] += cnt[i - 1][j];
                if(mp[i - 1][j] + mp[i][j] == 2) {
                    cnt[i][j]--;
                }
            } else {
                int t = cnt[i - 1][j] + cnt[i][j];
                if(mp[i - 1][j] == 1 && mp[i][j] == 1) --t;
                int s = cnt[i][j - 1] + cnt[i][j];
                if(mp[i][j - 1] == 1 && mp[i][j] == 1) --s;
                cnt[i][j] = min(s, t);
            }
        }
    }

    /*
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            cout << cnt[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << cnt[H][W] << endl;

    return 0;
}

