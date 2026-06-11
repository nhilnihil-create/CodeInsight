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
  int N,A,B,C,D;
  cin >> N >> A >> B >> C >> D;
  string S;
  cin >> S;

  int flag = 0;
  //岩が2連続になっていたらNo
  FOR(i,A-1,D){
    if(S.at(i)=='#'&&S.at(i+1)=='#'){
      flag = 1;
      break;
    }
  }

  //C>Dの時にB-1以降D+1以前に...がないとNo
  if(C>D){
    int flag2 = 0;
    FOR(i,B-2,D-1){
      if(S.at(i)=='.'&&S.at(i+1)=='.'&&S.at(i+2)=='.'){
        flag2 = 1;
      }
    }
    if(flag2 == 0){
      flag = 1;
    }
  }

  if(flag == 1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}