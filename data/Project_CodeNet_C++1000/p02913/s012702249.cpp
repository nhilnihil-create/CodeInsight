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

/* 
 * s と sのi文字目以降 の最長共通接頭辞を求める
 * O(|s|)
 * */
int Z_algorithm(string s) {
    int len = s.size();
    vector<int>a(len);
    a[0] = len;
    int i = 1, j = 0;

    while(i < len) {
        while(i + j < len && s[j] == s[i + j]) {
            ++j;

        }
        a[i] = j;
        if(j == 0) {
            ++i;
            continue;

        }

        int k = 1;
        while(i + k < len && k + a[k] < j) {
            a[i + k] = a[k];
            ++k;

        }
        i += k;
        j -= k;

    }

    int mx = 0;
    for(int i = 0; i < s.size(); ++i) {
        mx = max(mx, min(i, a[i]));

    }

    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;
    for(int i = 0; i < s.size(); ++i) {
        res = max(res, Z_algorithm(s.substr(i)));

    }
    cout << res << endl;
    return 0;
}

