#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<int>> A(3,vector<int>(3));
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < 3 ;j++){
      cin >> A.at(i).at(j);
    }
  }

  int N;
  cin >> N;
  vector<int> B(N);
  for(int i = 0 ; i < N ; i++){
    cin >> B.at(i);
  }


  vector<vector<bool>> flag(3,vector<bool>(3));
  for(int i = 0 ; i < N ; i++){
    int tmp = B.at(i);
    for(int j = 0 ; j < 3 ; j++){
      for(int k = 0 ; k < 3 ; k++){
        //cout << "A is " << A.at(j).at(k) << endl;
        if(tmp == A.at(j).at(k)){
          //cout << "ok" << endl;
          flag.at(j).at(k) = 1;
          goto SKIP;
        }
      }
    }
    SKIP:;
  }

  /*
  for(int i = 0 ; i < 3 ; i++){
    cout << "|-|-|-|" << endl;
    for(int j = 0 ; j < 3 ; j++){
      cout << "|" << flag[i][j];
    }
    cout << "|" << endl;
  }
  cout << "|-|-|-|" << endl;
  */

  string str = "No";

  for(int i = 0 ; i < 3 ; i++){
    if(flag[i][0] == flag[i][1] && flag[i][1] == flag[i][2] && flag[i][2] == 1){
      str = "Yes";
    }
  }
  for(int i = 0 ; i < 3 ; i++){
    if(flag[0][i] == flag[1][i] && flag[1][i] == flag[2][i] && flag[2][i] == 1){
      str = "Yes";
    }
  }

  if(flag[0][0] == flag[1][1] && flag[1][1] == flag[2][2] && flag[2][2] == 1){
    str = "Yes";
  }
  if(flag[0][2] == flag[1][1] && flag[1][1] == flag[2][0] && flag[2][0] == 1){
    str = "Yes";
  }

  cout << str << endl;
  return 0;
}
