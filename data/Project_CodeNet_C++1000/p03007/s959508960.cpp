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
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  sort(ALL(A));
  
  ll ans = 0;
  int cnt = 0;
  REP(i,N){
    if((cnt<=N-2&&A.at(i)<0)||i==0){
      ans+=-A.at(i);
      cnt++;
    }else{
      ans+=A.at(i);
    }
  }
  cout << ans << endl;

  int x = A.at(0);
  FOR(i,cnt,N-1){
    cout << x << " " << A.at(i) << endl;
    x=x-A.at(i);
  }
  cout << A.at(N-1) << " " << x << endl;
  x = A.at(N-1)-x;
  FOR(i,1,cnt){
    cout << x << " " << A.at(i) << endl;
    x=x-A.at(i);
  }
}