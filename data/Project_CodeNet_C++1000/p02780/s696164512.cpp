#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n,k; cin >> n >> k;
  vector<double> exp(n);
  double tmp; REP(i,n){ cin >> tmp; exp[i] = (1 + tmp) / 2;}
  vector<double> cumu(n+1,0);
  REP(i,n){
    cumu[i+1] = cumu[i] + exp[i];
  }
  double ans=0,sum=0;
  REP(i,n-k+1){
    sum = cumu[k+i] - cumu[i];
    ans = max(sum,ans);
  }
  printf("%.16lf",ans);
}