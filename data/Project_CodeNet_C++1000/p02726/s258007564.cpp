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
  int N,X,Y; cin >> N >> X >> Y;
  int dis;
  vector<int> ans(N);
  FOR(i,1,N){ 
    FOR(j,i+1,N+1){
      dis = min(min(j-i,abs(X-i)+1+abs(Y-j)),abs(Y-i)+1+abs(X-j));
      ans[dis]++;
    }
  }
  FOR(i,1,N)
    cout << ans[i] << endl;
}