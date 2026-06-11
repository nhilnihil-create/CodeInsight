#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
 
  vector<vector<int>> data(1000, vector<int>(3,0));
 
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0){
        data.at(i).at(j) = i+1;
      }
      else if (j == 1){
        data.at(i).at(j) = (i+1)*8/100;
      }
      else {
        data.at(i).at(j) = (i+1)/10;
      }
    }
  }
  
  for (int i = 0; i < 1000; i++) {
    if (A == data.at(i).at(1) && B == data.at(i).at(2)){
      cout << i + 1 << endl;
      break;
    }
    else if (i == 999){
      cout << -1 << endl;
    }
  }
}

