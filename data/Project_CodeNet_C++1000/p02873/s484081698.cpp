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

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 500005;

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

    string s;
    cin >> s;
    LL res[SIZE];
    for(int i = 0; i < SIZE; ++i) {
        res[i] = -1;
    }

    if(s[0] == '<') {
        res[0] = 0;
        int p = 0;
        while(p < s.size() && s[p] == '<') {
            res[p + 1] = res[p] + 1;
            ++p;
        }
    }

    for(int i = 1; i < s.size(); ++i) {
        if(s[i - 1] == '>' && s[i] == '<') {
            res[i] = 0;
            int p = i - 1;
            while(p >= 0 && s[p] == '>' && res[p] < res[p + 1] + 1) {
                res[p] = res[p + 1] + 1;
                --p;
            }

            p = i;
            while(p < s.size() && s[p] == '<') {
                res[p + 1] = res[p] + 1;
                ++p;
            }
        }
    }

    if(s[s.size() - 1] == '>') {
        res[s.size()] = 0;
        res[s.size() - 1] = 1;
        int p = s.size() - 2;
        while(p >= 0 && s[p] == '>' && res[p] < res[p + 1] + 1) {
            res[p] = res[p + 1] + 1;
            --p;
        }
    }

    LL sum = 0;
    for(int i = 0; i <= s.size(); ++i) {
        sum += res[i];
    }
    cout << sum << endl;
    return 0;
}

