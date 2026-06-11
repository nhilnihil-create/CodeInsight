#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  vector<vector<int>> a(3,vector<int>(3));
  REP(i,3){
    REP(j,3){
      cin >> a[i][j];
    }
  }
  vector<vector<bool>> a_check(3,vector<bool>(3,false));
  int n; 
  cin >> n;
  REP(i,n){
    int b;
    cin >> b;
    REP(j,3){
      REP(k,3){
        if(b == a[j][k]){
          a_check[j][k] = true;
        }
      }
    }
  }
    
  bool ok = false;
  if(a_check[0][0] && a_check[1][0] && a_check[2][0]){
    ok = true;
  }
  if(a_check[0][1] && a_check[1][1] && a_check[2][1]){
    ok = true;
  }
  if(a_check[0][2] && a_check[1][2] && a_check[2][2]){
    ok = true;
  }
  if(a_check[0][0] && a_check[0][1] && a_check[0][2]){
    ok = true;
  }
  if(a_check[1][0] && a_check[1][1] && a_check[1][2]){
    ok = true;
  }
  if(a_check[2][0] && a_check[2][1] && a_check[2][2]){
    ok = true;
  }  
  if(a_check[0][0] && a_check[1][1] && a_check[1][1]){
    ok = true;
  }     
  if(a_check[2][0] && a_check[1][1] && a_check[0][2]){
    ok = true;
  }
  
 if(ok) cout << "Yes" << endl;
 else cout << "No" << endl;
     
}