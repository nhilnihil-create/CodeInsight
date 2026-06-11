#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int main() {
  int N = 523458;
  vector<int> v(N, 1);
  v[0]=v[1]=0;
  REP(i,N) {
    if (v[i])
      for (int j=i*2; j<N; j+=i)
        v[j] = 0;
  }
  int n;
  while(cin>>n,n) {
    int res =0;
    for (int i=n+1; i<=2*n; ++i)
      if (v[i])
        res++;
    cout <<res << endl;
  }
}