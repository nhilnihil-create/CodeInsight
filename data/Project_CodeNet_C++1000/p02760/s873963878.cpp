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
  vector<vector<int>> data(3,vector<int>(3));
  REP(i,3){
    REP(j,3){
      cin >> data[i][j];
    }
  }
  int N; cin >> N;
  vector<vector<bool>> bingo(3,vector<bool>(3));
  REP(i,N){
    int tmp; cin >> tmp;
    REP(j,3){
      REP(k,3){
        if(tmp == data[j][k])
          bingo[j][k]=true;
      }
    }
  }
  bool flag=false;
  REP(i,3){
    if(bingo[i][0] && bingo[i][1] && bingo[i][2]) flag = true;
  }
  REP(i,3){
 	if(bingo[0][i] && bingo[1][i] && bingo[2][i]) flag = true;
  }
  if(bingo[0][0] && bingo[1][1] && bingo[2][2]) flag = true;
  if(bingo[0][2] && bingo[1][1] && bingo[2][0]) flag = true;
  if(flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}