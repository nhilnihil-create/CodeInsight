#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG




int main() {
  vector<vector<int>> A(3, vector<int>(3));
  vector<vector<int>> ju(3, vector<int>(3));
  
  for(ll i=0; i<3;i++){
    for(ll j= 0 ; j<3; j++){
      cin >> A[i][j];
    }
  }
  ll N;
  cin >> N;

  for(ll i=0; i<N;i++){
    ll tmp;
    cin >> tmp;
    for(ll i=0; i<3;i++){
      for(ll j= 0 ; j<3; j++){
        if(A[i][j] == tmp) ju[i][j] = 1;
      }
    }
  }

  for(ll i=0; i<3;i++){   
    if(ju[i][0] == 1 && ju[i][1] == 1 && ju[i][2] == 1){
      cout << "Yes" << endl;
      return 0;
    }
  }

  for(ll j=0; j<3;j++){   
    if(ju[0][j] == 1 && ju[1][j] == 1 && ju[2][j] == 1){
      cout << "Yes" << endl;
      return 0;
    }
  }

  if(ju[0][0] == 1 && ju[1][1] == 1 && ju[2][2] == 1){
      cout << "Yes" << endl;
      return 0;
  }

  if(ju[0][2] == 1 && ju[1][1] == 1 && ju[2][0] == 1){
      cout << "Yes" << endl;
      return 0;
  }
  

  cout << "No" << endl;
  return 0;
}
