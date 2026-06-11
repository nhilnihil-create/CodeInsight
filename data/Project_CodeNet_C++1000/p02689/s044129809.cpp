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
  int N,M; cin >> N >> M;
  vector<int> elev(N+1); FOR(i,1,N+1) cin >> elev.at(i);
  vector<vector<int>> road(N+1); 
  int tmp1,tmp2;
  int ans = 0;
  bool goodflag;
    
  REP(i,M){
    cin >> tmp1 >> tmp2;
    road.at(tmp1).push_back(tmp2);
    road.at(tmp2).push_back(tmp1);
  }
  FOR(i,1,N+1) road.at(i).push_back(-1);
  
  FOR(i,1,N+1){
    goodflag = true;
    for(int j = 0; road.at(i).at(j) != -1; j++){
      if(elev.at(i) <= elev.at(road.at(i).at(j))){
        goodflag = false;
        break;
      }
    }
    if(goodflag)
      ans++;
  }
  cout << ans << endl;
}