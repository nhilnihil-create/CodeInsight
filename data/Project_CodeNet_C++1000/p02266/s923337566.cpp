#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
template<class T> using vv=vector<vector< T > >;

int main() {
  string str;
  cin >> str;
  vi ground(str.length()+1);
  ground[0] = 0;
  rep(i, (int)str.length()) {
    if (str[i] == '_') {
      ground[i+1] = ground[i];
    } else if (str[i] == '/') {
      ground[i+1] = ground[i] + 1;
    } else {
      ground[i+1] = ground[i] - 1;
    }
  }

  int A = 0;
  vi L;
  vi vpd(str.length()+1, 0);
  vi vp(str.length()+1, 0);
  vi st; // x coordinate
  rep(i, (int)str.length()) {
    if ( str[i] == '\\' ) {
      st.pb(i);
    } else if ( str[i] == '/' && !st.empty() ) {
      vpd[st.back()] +=1;
      vpd[st.back()+1] += 1;
      vpd[i] += -1;
      vpd[i+1] += -1;

      st.pop_back();
    }
  }

  rep(i, (int)str.length()) {
    vp[i+1] = vp[i] + vpd[i];
  }

  int cond = 0; // 1: water
  FOR(i, 1, (int)str.length()+1) {
    if (cond == 0 && vp[i] == 1) {
      L.pb(0);
    }
    if (vp[i] == 1) {
      cond = 1 - cond;
    }
    if (vp[i] != 0) {
      L.back() += vp[i];
    }
  }

  rep(i, (int)L.size()) {
    L[i] /= 2;
    A += L[i];
  }

  printf("%d\n", A);
  printf("%lu", L.size());
  rep(i, (int)L.size()) {
    printf(" %d", L[i]);
  }
  printf("\n");

  return 0;
}