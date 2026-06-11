#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr, __VA_ARGS__)
//#define LOG(...)
#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define RREP(i, n) for(int i = (int)(n - 1); i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SQ(n) (n) * (n)
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<vll> vvll;

int main() {
  int h, w = 5;
  while(cin >> h, h) {
    vvi field(h + 1, vi(w));
    REP(y, h) REP(x, w){
      cin >> field[y][x];
    }
    REP(x, w){
      field[h][x] = x + 1;
    }

    int res = 0;
    bool update = true;
    while(update) {
      update = false;
      // erase
      REP(y, h) {
        auto &ln = field[y];
        auto c = ln.begin() + 2;
        auto l = c;
        auto r = c;
        while(l != ln.begin() && *(l - 1) == *c) l--;
        while(r != ln.end() && *(r + 1) == *c)  r++;
        if (++r - l >= 3) {
          res += (r - l) * *c;
          fill(l, r, 0);
        }
      }

      // drop
      REP(x, w) {
        RREP(y, h - 1) {
          if (!field[y + 1][x] && field[y][x]) {
            swap(field[y + 1][x], field[y][x]);
            update = true;
            y += 2;
          }
        }
      }
    }

    cout << res << endl;

  }
}