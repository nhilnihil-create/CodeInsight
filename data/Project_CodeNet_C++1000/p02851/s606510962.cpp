
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;

ll vs[200000+10];
ll cs[200000+10];
map<ll, queue<int> > table;

int main(void) {
  int n;
  ll k;
  scanf("%d%lld", &n, &k);
  cs[0] = 0;
  REP(i, n) {
    scanf("%lld", &vs[i]);
    vs[i] = (vs[i] + k - 1) % k;
    cs[i+1] = (cs[i] + vs[i]) % k;
  }
  ll res = 0;
  // REP(i, n) {
  //   cerr << i << " : " << vs[i] << endl;
  // }
  // cerr << endl;
  // REP(i, n+1) {
  //   cerr << i << " : " << cs[i] << endl;
  // }
  for(int i = n; i >= 0; --i) {
    ll cur = cs[i];
    ll opp = cur;
    while(!table[opp].empty() && table[opp].front() >= i+k) {
      table[opp].pop();
    }
    // if(table[opp].size() > 0) {
    //   cerr << i << " " << table[opp].size() << endl;
    // }
    res += table[opp].size();
    table[cur].push(i);
  }
  cout << res << endl;

  return 0;
}
