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

bool check(int idx);

LL N, M, V, P;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> V >> P;
    for(int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        v.pb(a);
    }
    sort(all(v), greater<>());

    int l = 0;
    int r = N;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << r << endl;

    return 0;
}

bool check(int idx) {
    int t = v[idx] + M;

    LL vot = M * V - M;

    vector<int> r;
    int res = N;
    for(int i = 0; i < N; ++i) {
        if(i == idx) continue;
        if(t < v[i]) {
            vot -= M;
        } else {
            r.pb(v[i]);
            --res;
        }
    }

    if(res > P) {
        return false;
    }

    sort(all(r), greater<>());
    for(int i = 0; i < r.size(); ++i) {
        if(t - r[i] < M && res < P) {
            vot -= M;
            ++res;
        } else {
            vot -= min((int)M, t - r[i]);
        }
    }

    return vot <= 0;
}

