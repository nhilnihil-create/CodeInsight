#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> bingo(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> bingo.at(i).at(j);
    }
  }
  int n;
  cin >> n;
  vector<int> number(n);
  for(int i=0;i<n;i++){
    cin >> number.at(i);
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<n;k++){
        if( number.at(k) == bingo.at(i).at(j) ){
          bingo.at(i).at(j) = 0;
        }
      }
    }
  }
  bool x = true;
  for(int i=0;i<3;i++){
    if( bingo.at(i).at(0) == 0 && bingo.at(i).at(1) == 0 && bingo.at(i).at(2) == 0  ){
      cout << "Yes" <<endl;
      x = false;
      break;
    }
    else if( bingo.at(0).at(i) == 0 && bingo.at(1).at(i) == 0 && bingo.at(2).at(i) == 0 ){
      cout << "Yes" <<endl;
      x = false;
      break;
    }
    else if( bingo.at(0).at(0) == 0 && bingo.at(1).at(1) == 0 && bingo.at(2).at(2) == 0 ){
      cout << "Yes" <<endl;
      x = false;
      break;
    }
    else if( bingo.at(2).at(0) == 0 && bingo.at(1).at(1) == 0 && bingo.at(0).at(2) == 0 ){
      cout << "Yes" <<endl;
      x = false;
      break;
    }
  }
  if(x)
    cout << "No" << endl;
}
