#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<vector<int>> card(3, vector<int>(3));
  vector<vector<bool>> check(3, vector<bool>(3, false));
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cin >> card.at(i).at(j);
    }
  }
  int N, b;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> b;
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        if (b == card.at(i).at(j)){
          check.at(i).at(j) = true;
        }
      }
    }
  }
  
  bool ans = false;
  
  if (check.at(0).at(0) == true && check.at(1).at(0) == true  && check.at(2).at(0) == true){
    ans = true;
  }
  if (check.at(0).at(1) == true && check.at(1).at(1) == true  && check.at(2).at(1) == true){
    ans = true;
  }
  if (check.at(0).at(2) == true && check.at(1).at(2) == true  && check.at(2).at(2) == true){
    ans = true;
  }
  if (check.at(0).at(0) == true && check.at(0).at(1) == true  && check.at(0).at(2) == true){
    ans = true;
  }
  if (check.at(1).at(0) == true && check.at(1).at(1) == true  && check.at(1).at(2) == true){
    ans = true;
  }
  if (check.at(2).at(0) == true && check.at(2).at(1) == true  && check.at(2).at(2) == true){
    ans = true;
  }
  if (check.at(0).at(0) == true && check.at(1).at(1) == true  && check.at(2).at(2) == true){
    ans = true;
  }
  if (check.at(0).at(2) == true && check.at(1).at(1) == true  && check.at(2).at(0) == true){
    ans = true;
  }
  
  if (ans) cout << "Yes";
  else cout << "No";
}
  
  