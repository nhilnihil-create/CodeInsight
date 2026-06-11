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

    int n;
    string s;
    cin >> n >> s;

    if(s[0] == 'W' || s[n * 2 - 1] == 'W') {
        cout << 0 << endl;
        return 0;

    }

    vector<char> d;
    int l, r;
    l = r = 0;
    ++l;
    d.pb('L');
    for(int i = 1; i < n * 2; ++i) {
        if(s[i] == s[i - 1]) {
            if(d[i - 1] == 'L') {
                d.pb('R');
                ++r;

            } else {
                d.pb('L');
                ++l;

            }
        } else {
            if(d[i - 1] == 'L') {
                d.pb('L');
                ++l;

            } else {
                d.pb('R');
                ++r;

            }
        }
    }

    if(l != r) {
        cout << 0 << endl;
        return 0;

    }

    LL res = 1;
    l = r = 0;
    for(int i = 0; i < n * 2; ++i) {
        if(d[i] == 'L') {
            ++l;

        } else {
            ++r;
            res = res * l % MOD;
            l--;

        }
    }

    for(int i = 1; i <= n; ++i) {
        res = res * i % MOD;

    }
    cout << res << endl;
    return 0;
}

