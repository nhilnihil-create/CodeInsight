#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr, __VA_ARGS__)
//#define LOG(...)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define RFOR(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define RREP(i, n) for (int i = (int)(n - 1); i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SZ(a) ((int)(a).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define SQ(x) ((x) * (x))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    int n;
    cin >> n;
    REP(i, n) {
        int y, m, d;
        cin >> y >> m >> d;
        int cnt = 0;
        while (1) {
            if (y == 1000 && m == 1 && d == 1) break;
            if (y % 3 == 0) {
                if (d == 20) {
                    m++;
                    d = 1;
                } else {
                    d++;
                }
                if (m == 11) {
                    y++;
                    m = 1;
                }
            } else {
                if (m % 2 == 0) {
                    if (d == 19) {
                        m++;
                        d = 1;
                    } else {
                        d++;
                    }
                } else {
                    if (d == 20) {
                        m++;
                        d = 1;
                    } else {
                        d++;
                    }
                }
                if (m == 11) {
                    y++;
                    m = 1;
                }
            }
            cnt++;
        }
        cout << cnt << endl;
    }
}