#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int a[3][3];
  rep(i,3)rep(j,3){
    cin >> a[i][j];
  }
  int N;
  cin >> N;
  int b;
  rep(i,N){
    cin >> b;
    rep(i,3)rep(j,3){
      if(a[i][j] == b) a[i][j] = 0;
    }
  }
  bool ans = false;
  rep(i,3){
    if(a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0 ) ans = true; 
  }
  rep(i,3){
    if(a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0 ) ans = true; 
  }
  if(a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0 ) ans = true; 
  if(a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0 ) ans = true; 
  
  cout << (ans? "Yes": "No") << endl;
  







	return 0;
}

