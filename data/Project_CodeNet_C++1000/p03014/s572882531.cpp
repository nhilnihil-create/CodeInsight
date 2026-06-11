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
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  REP(i, H) cin >> A[i];
  vector<vector<int>> ans(H,vector<int> (W,0));
  REP(i,H){
    vector<int> X;
    int cnt = 0;
    REP(j,W){
      if(A.at(i).at(j)=='.'){
        cnt++;
      }else{
        X.push_back(cnt);
        cnt=0;
      }
    }
    X.push_back(cnt);
    int cnt2 = 0;
    REP(j,W){
      if(A.at(i).at(j)=='#'){
        cnt2++;
      }else{
        ans.at(i).at(j)+=X.at(cnt2);
      }
    }
  }
  REP(i,W){
    vector<int> X;
    int cnt = 0;
    REP(j,H){
      if(A.at(j).at(i)=='.'){
        cnt++;
      }else{
        X.push_back(cnt);
        cnt=0;
      }
    }
    X.push_back(cnt);
    int cnt2 = 0;
    REP(j,H){
      if(A.at(j).at(i)=='#'){
        cnt2++;
      }else{
        ans.at(j).at(i)+=X.at(cnt2);
      }
    }
  }

  int MAX=0;
  REP(i,H){
    REP(j,W){
      MAX=max(MAX,ans.at(i).at(j));
    }
  }

  cout << MAX-1 << endl;
}