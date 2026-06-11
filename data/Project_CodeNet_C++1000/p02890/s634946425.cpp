
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

map<int,int> hist;
int n;
vector<int> vs;
vector<int> cs;

bool isOK(int k, int h) {
  int idx = lower_bound(vs.begin(), vs.end(), h) - vs.begin();
  ll total = cs[idx] + ll(vs.size()-idx) * h;
  // cerr << "> " << k << " " << h << " " << idx << " " << total << " " << ll(k) * h << endl;
  return total >= ll(k) * h;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    int v;
    scanf("%d", &v);
    hist[v]++;
  }
  for(auto it : hist) {
    vs.push_back(it.second);
  }
  sort(vs.begin(), vs.end());
  cs.push_back(0);
  for(int v : vs) {
    int last = cs.back();
    cs.push_back(last + v);
    // cerr << ">>" << v << " " << cs.back() << endl;
  }
  for(int k = 1; k <= n; ++k) {
    int left = 0;
    int right = n+1;
    while(left + 1 < right) {
      int mid = (left + right) / 2;
      if(isOK(k, mid)) {
        left = mid;
      } else {
        right = mid;
      }
    }
    printf("%d\n", left);
  }
  
  return 0;
}
