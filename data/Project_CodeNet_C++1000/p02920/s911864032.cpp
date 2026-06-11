#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;
long long int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
long long int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  int n; cin >> n;
  vector<lint> s(1 << n);
  for(int i = 0; i < (1 << n); i++) cin >> s[i];
  sort(RALL(s));
  s.push_back(-1); //番兵
  priority_queue<lint> pq;
  pq.push(1 << n); //連結成分の個数が大きい順に入っている

  int id = 0;
  while(s[id] != -1) {
    int num = s[id];
    int cnt = 0;
    while(s[id] == num) {
      cnt++;
      id++;
    }

    if(cnt > pq.size()) {
      cout << "No" << endl;
      return 0;
    }
    
    vector<lint> cs;
    while(cnt--) {
      lint c = pq.top();
      cs.push_back(c);
      pq.pop();
    }

    for(int i = 0; i < cs.size(); i++) {
      lint c = cs[i] / 2;
      while(c) {
        pq.push(c);
        c /= 2;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
