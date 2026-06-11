#include <bits/stdc++.h>
using namespace std;

int main() {
  
  vector<vector<int>> vec(3, vector<int>(3));
  for(int i = 0; i < 3; i++){
    for(int j = 0;  j < 3; j++){
      int a;
      cin >> a;
      vec.at(i).at(j) = a;
    }
  }
  
  int n;
  cin >> n;
  
  for(int i = 0; i<n; i++){
    int b;
    cin >> b;
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        if(vec.at(j).at(k) == b) vec.at(j).at(k) = 0;
      }
    }
  }
  
  int ans = 0;
  
  for(int i = 0; i<3; i++){
    if(vec.at(i).at(0) == vec.at(i).at(1) && vec.at(i).at(1) == vec.at(i).at(2)){
      ans = 1;
      break;
    }
    if(vec.at(0).at(i) == vec.at(1).at(i) && vec.at(1).at(i) == vec.at(2).at(i)){
      ans = 1;
      break;
    }
    if(vec.at(0).at(0) == vec.at(1).at(1) && vec.at(1).at(1) == vec.at(2).at(2)){
      ans = 1;
      break;
    }
    if(vec.at(0).at(2) == vec.at(1).at(1) && vec.at(1).at(1) == vec.at(2).at(0)){
      ans = 1;
      break;
    }
  }
  
  if(ans == 1){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
  
  
  
  
}

