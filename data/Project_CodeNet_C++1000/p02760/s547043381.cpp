#include <bits/stdc++.h>
using namespace std;

int main() {
  //0 1 2
  //3 4 5
  //6 7 8
  vector<int>vec(9);
  for(int i=0; i<9; i++){
    cin >> vec[i];
  }
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    int j;
    cin >> j;
    for(int k=0; k<9; k++){
      if(vec[k] == j){
        vec[k] = 0;
      }
    }
  }
  if(vec[0] == 0 && vec[1] == 0 && vec[2] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(vec[3] == 0 && vec[4] == 0 && vec[5] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(vec[6] == 0 && vec[7] == 0 && vec[8] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(vec[0] == 0 && vec[3] == 0 &&  vec[6] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(vec[1] == 0 && vec[4] == 0 && vec[7] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(vec[2] == 0 && vec[5] == 0 && vec[8] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(vec[0] == 0 && vec[4] == 0 && vec[8] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(vec[2] == 0 && vec[4] == 0 && vec[6] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
