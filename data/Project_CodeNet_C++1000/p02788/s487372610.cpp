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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL n, d, a;
    cin >> n >> d >> a;
    vector<LP> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].F >> v[i].S;

    }
    sort(all(v));

    queue<LP> q;
    int pos = 0;
    LL res = 0;
    LL sum = 0;
    while(pos < n) {
        while(!q.empty() && v[pos].F > q.front().F) {
            sum -= q.front().S;
            q.pop();

        }

        v[pos].S -= sum;
        if(v[pos].S > 0) {
            LL tmp = v[pos].S / a;
            if(v[pos].S % a != 0) ++tmp;
            sum += a * tmp;
            res += tmp;
            q.push(MP(v[pos].F + d * 2, a * tmp));

        }
        ++pos;
    }
    cout << res << endl;

    return 0;
}

