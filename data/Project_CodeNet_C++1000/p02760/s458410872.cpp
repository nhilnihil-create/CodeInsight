#include<bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;


int main() {
  int a[3][3];
  REP(i,3){
    REP(j,3){
      cin >> a[i][j];
    }
  }
  
  int n;
  cin >> n;
  vector<vector<bool>> ok(3,vector<bool>(3,false));
  int b;
  REP(i,n){
    cin >> b;
    REP(j,3){
      REP(k,3){
        ok[j][k] = ok[j][k] | (a[j][k] == b);
      }
    }
  }
  
  bool res = false;
  
  REP(i,3){
    res |= ok[0][i] && ok[1][i] && ok[2][i];
    res |= ok[i][0] && ok[i][1] && ok[i][2];
  }
  
  res |= ok[0][0] && ok[1][1] && ok[2][2];
  
  res |= ok[0][2] && ok[1][1] && ok[2][0];
  if(res){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}