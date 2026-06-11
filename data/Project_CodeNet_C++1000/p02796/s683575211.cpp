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
  vector<vector<int>> A(N,vector<int>(2));
  vector<vector<int>> B(N,vector<int>(2));
  REP(i, N){
    REP(j, 2){
      cin >> A.at(i).at(j);
    }
    B.at(i).at(0)=A.at(i).at(0)+A.at(i).at(1);
    B.at(i).at(1)=A.at(i).at(0)-A.at(i).at(1);
  }
  
  sort(ALL(B));
  int now = B.at(0).at(0);
  int cnt = 1;
  FOR(i,1,N){
    if(now<=B.at(i).at(1)){
      cnt++;
      now=B.at(i).at(0);
    }
  }

  cout << cnt << endl;
}