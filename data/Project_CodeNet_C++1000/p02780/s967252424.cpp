#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N, K;
  cin >> N >> K;
  vector<int> v;
  rep(i,N){
    int a;
    cin >> a;
    v.push_back(a);
  }

  vector<double> w(N);
  rep(i,N){
    w[i] = (v[i]+1)/2.0;
  }

  double sum = 0;
  rep(i,K) sum += w[i];

  double ret = sum;
  REP(i,K,N){
    sum += w[i];
    sum -= w[i-K];

    ret = max(ret, sum);
  }

  printf("%.12lf\n", ret);
  
  return 0;
}
