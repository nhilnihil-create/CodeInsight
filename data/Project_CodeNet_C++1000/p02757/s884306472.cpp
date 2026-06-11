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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, P;
    cin >> N >> P;
    string s;
    cin >> s;
    reverse(all(s));
    LL res = 0;
    if(P == 2) {
        for(int i = 0; i < s.size(); ++i) {
            if((s[i] - '0') % 2 == 0) {
                res += N - i;

            }
        }
        cout << res << endl;
        return 0;
    }
    if(P == 5) {
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0' || s[i] == '5') {
                res += N - i;

            }
        }
        cout << res << endl;
        return 0;
    }
    map<int, LL> mp;
    int t = 0;
    int d = 1;
    for(int i = 0; i < s.size(); ++i) {
        t += (s[i] - '0') * d;
        t %= P;
        mp[t]++;
        d *= 10;
        d %= P;

    }

    res += mp[0] * (mp[0] + 1) / 2;
    /*
    int l = 1, r = 2018;
    while(l <= r) {
        res += mp[l] * mp[r];
        ++l; --r;

    }*/
    for(int i = 1; i < P; ++i) {
        res += mp[i] * (mp[i] - 1) / 2;

    }
    cout << res << endl;
    return 0;
}

