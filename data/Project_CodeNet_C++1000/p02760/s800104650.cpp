#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e14;
using Graph = vector<vector<int>>;

signed main(){
  vector<vector<int>> A(3, vector<int>(3));
  for( int i = 0; i < 3; i++ ){
    for( int j = 0; j < 3; j++ ) cin >> A[i][j];
  }

  int N;
  cin >> N;
  for( int n = 0; n < N; n++ ){
    int B;
    cin >> B;
    for( int i = 0; i < 3; i++ ){
      for( int j = 0; j < 3; j++ ){
        if( A[i][j] == B ) A[i][j] = -1;
      }
    }
  }

  //横
  for( int i = 0; i < 3; i++ ){
    bool fg = 1;
    for( int j = 0; j < 3; j++ ){
      if( A[i][j] != -1 ) fg = 0;
    }
    if( fg ){
      cout << "Yes" << endl;
      return 0;
    }
  }

  //たて
  for( int i = 0; i < 3; i++ ){
    bool fg = 1;
    for( int j = 0; j < 3; j++ ){
      if( A[j][i] != -1 ) fg = 0;
    }
    if( fg ){
      cout << "Yes" << endl;
      return 0;
    }
  }

  //ななめ
  if( A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1 ){
    cout << "Yes" << endl;
    return 0;
  }
  if( A[0][2] == -1 && A[1][1] == -1 && A[2][0] == -1 ){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;




}
