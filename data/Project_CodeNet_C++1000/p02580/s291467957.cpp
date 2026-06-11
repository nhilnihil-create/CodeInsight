//競技プログラミング用のテンプレート
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <stack>
#include <limits>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define repr(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;
//エイリアス
using ll = long long int;
using p = pair<int, int>;
using pl = pair<ll, ll>;
using v = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vl = vector<ll>;

//定数
const int intmax = numeric_limits<int>::max();
const ll llmax = numeric_limits<ll>::max();
const ll mod = 1e9 + 7;
const double pi = M_PI;

bool find(int fixIndex, v fixRef, v targetRef, v target, int limit, int other) {
  for (int i = 0; i < fixRef.size(); i++) {
    if (fixIndex == fixRef[i]) {
      target[targetRef[i]]--;
    }
  }
  int tmp = 0;
  for (int i = 0; i < target.size(); i++) {
    tmp = max(tmp, target[i]);
  }
  return tmp + other == limit;
}

int main()
{
  int h, w, m;
  cin >> h >> w >> m;
  map<p, int> memo;
  v hs(m, 0);
  v ws(m, 0);
  v hcnt(h, 0); v wcnt(w, 0);
  rep(i, m) {
    cin >> hs[i] >> ws[i];
    hcnt[--hs[i]]++;
    wcnt[--ws[i]]++;
    p tmp;
    tmp.first = hs[i];
    tmp.second = ws[i];
    memo[tmp] = 1;
  }

  int hmax = 0; int wmax = 0;
  int hindex = 0; int windex = 0;
  rep(i, h) {
    if (hmax < hcnt[i]) {
      hmax = hcnt[i];
      hindex = i;
    }
  }
  rep(i, w) {
    if (wmax < wcnt[i]) {
      wmax = wcnt[i];
      windex = i;
    }
  }

  if (memo.count({hindex, windex}) == 0) {
    cout << hmax + wmax << endl;
  } else {
    if (find(hindex, hs, ws, wcnt, hmax + wmax, hmax) || find(windex, ws, hs, hcnt, hmax + wmax, wmax)) {
      cout << hmax + wmax << endl;
    } else {
      cout << hmax + wmax - 1 << endl;
    }
  }
}
