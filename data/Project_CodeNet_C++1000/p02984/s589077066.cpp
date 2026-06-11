#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll N;
  cin >> N;
  ll sum = 0;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
    sum+=A[i];
  }
  sum/=2;

  ll x=0;
  for(int i = 0;i<N-1;i+=2){
    x+=A[i+1];
  }
  vector<ll> B(N);
  B[0]=(sum-x)*2;
  FOR(i,1,N){
    B[i]=(A[i-1]-(B[i-1]/2))*2;
  }

  REP(i,N){
    cout << B[i] << endl;
  }
}