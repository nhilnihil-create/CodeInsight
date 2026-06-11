
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

vector<pair<ll,int> > vs;
int main(void) {
  int X, Y, A, B, C;
  scanf("%d%d%d%d%d", &X, &Y, &A, &B, &C);
  REP(i, A) {
    ll v;
    scanf("%lld", &v);
    vs.push_back(make_pair(v, 2));
  }
  REP(i, B) {
    ll v;
    scanf("%lld", &v);
    vs.push_back(make_pair(v, 1));
  }
  REP(i, C) {
    ll v;
    scanf("%lld", &v);
    vs.push_back(make_pair(v, 0));
  }
  sort(vs.begin(), vs.end());
  reverse(vs.begin(), vs.end());
  ll res = 0;
  int r = 0, g = 0, b = 0;
  REP(i, vs.size()) {
    ll v = vs[i].first;
    int t = vs[i].second;
    if(t == 2) {
      if(r < X) {
        ++r;
        res += v;
      }
    } else if(t == 1) {
      if(g < Y) {
        ++g;
        res += v;
      }
    } else {
      ++b;
      res += v;
    }
    // cerr << r << " " << g << " " << b << " " << res << endl;
    if(r + g + b == X + Y) {
      break;
    }
  }
  cout << res << endl;
  return 0;
}
