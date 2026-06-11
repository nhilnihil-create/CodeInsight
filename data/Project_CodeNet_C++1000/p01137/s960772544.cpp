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
  int e;
  while(cin >> e, e) {
    int res = (int)1e9;
    for(int z = 0; z * z * z <= e; z++) {
      for(int y = 0; z * z * z + y * y <= e; y++) {
        int x = e - (z * z * z + y * y);
        res = min(res, z + y + x);
      }
    }
    cout << res << endl;
  }
}