#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
//ranker
using namespace std;

#define REPS(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (int i = (a); i >= n; --i)
#define DEP(i, n) DEPS(i, n, 0)

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using D = double;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int M, min, max;

  while(1){
    cin >> M >> min >> max;

    if(M == 0 && min == 0 && max == 0) break;

    int P[M];
    REP(i, M) cin >> P[i];

    int gomi = 0;
    int cnt = 0;
    REPS(i, min-1, max){
      if(gomi <= P[i]-P[i+1]){
      gomi = P[i]-P[i+1];
      cnt = i+1;
    }
  }
    cout << cnt << endl;
  }

  return 0;
}