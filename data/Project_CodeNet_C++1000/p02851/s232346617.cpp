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

    int n, k;
    cin >> n >> k;
    vector<LL> sum(n + 1);
    sum[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
        sum[i] %= k;

    }

    map<LL, LL> mp;
    queue<LL> q;
    LL res = 0;
    for(int i = 0; i <= n; ++i) {
        LL t = (sum[i] - i) % k;
        if(t < 0) t += k;

        res += mp[t];
        mp[t]++;
        q.push(t);
        if(q.size() >= k) {
            mp[q.front()]--;
            q.pop();

        }
    }
    cout << res << endl;
    return 0;
}

