#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> A(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<bool>> bingo(3,vector<bool>(3,false));
  int N;
  cin >> N;
  for(int i=0;i<N;i++){
    int B;
    cin >> B;
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(A.at(j).at(k)==B){
          bingo.at(j).at(k)=true;
        }
      }
    }
  }
  for(int i=0;i<3;i++){
    if(bingo.at(i).at(0) && bingo.at(i).at(1) && bingo.at(i).at(2)){
      cout << "Yes" << endl;
      return 0;
    }
    if(bingo.at(0).at(i) && bingo.at(1).at(i) && bingo.at(2).at(i)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  if(bingo.at(0).at(0) && bingo.at(1).at(1) && bingo.at(2).at(2)){
      cout << "Yes" << endl;
      return 0;
  }
  if(bingo.at(2).at(0) && bingo.at(1).at(1) && bingo.at(0).at(2)){
      cout << "Yes" << endl;
      return 0;
  }
  cout << "No" << endl;
}
  