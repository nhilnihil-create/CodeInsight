#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  int h, w, m;
  cin >> h >> w >> m;
  vector<int> numx(w + 1);
  vector<int> numy(h + 1);
  set<P> s;
  rep(i, m) {
    int hi, wi;
    cin >> hi >> wi;
    numx[wi]++;
    numy[hi]++;
    s.insert(make_pair(wi, hi));
  }
  int maxx = 0;
  int maxy = 0;
  for (int x : numx) maxx = max(x, maxx);
  for (int y : numy) maxy = max(y, maxy);
  vector<int> maxx_v;
  vector<int> maxy_v;
  rep(i, w + 1) {
    if (numx[i] == maxx) maxx_v.push_back(i);
  }
  rep(i, h + 1) {
    if (numy[i] == maxy) maxy_v.push_back(i);
  }
  for (int x : maxx_v) {
    for (int y : maxy_v) {
      if (s.count(make_pair(x, y)) == 0) {
        cout << maxx + maxy << endl;
        return 0;
      }
    }
  }

  cout << maxx + maxy - 1 << endl;
  return 0;
}