#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int N;
  cin >> N;

  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  ll sum = 0;
  REP(i,N){
    sum+=A.at(i);
  }
  ll sum2 = 0;
  ll sum3 = 0;
  REP(i,N-1){
    sum2+=A.at(i);
    sum3 = sum2+A.at(i+1);
    if(sum3>sum/2){
      break;
    }
  }
  cout << min(sum-sum2*2,sum3*2-sum) << endl;
}