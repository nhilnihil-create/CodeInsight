#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
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

    int n, k;
    cin >> n >> k;
    vector<LL> v(n);
    LL sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];

    }

    vector<LL> sdiv = Div(sum);
    vector<LL> p;
    LL res = 1;
    for(int i = 0; i < sdiv.size(); ++i) {
        p.clear();
        for(int j = 0; j < n; ++j) {
            p.pb(v[j] % sdiv[i]);

        }
        sort(all(p));

        for(int j = 0; j <= n; ++j) {
            LL a, b;
            a = b = 0;
            for(int l = 0; l < j; ++l) {
                a += p[l];

            }
            for(int l = j; l < n; ++l) {
                b += sdiv[i] - p[l];

            }
            if(a == b && a <= k) {
                res = max(res, sdiv[i]);

            }
        }
    }
    cout << res << endl;
    return 0;
}
