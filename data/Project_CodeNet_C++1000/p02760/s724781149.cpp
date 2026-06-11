#include <iostream>

using namespace std;

int v[3][3];
bool mark[3][3];

int main() {

  int n, p;
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      cin >> v[i][j];
    }
  }
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> p;
    for(int i = 0;i < 3;i++){
      for(int j = 0;j < 3;j++){
        if(p == v[i][j]){
          mark[i][j] = true;
        }
      }
    }
  }
  if(mark[0][0] == true && mark[1][1] == true && mark[2][2] == true){
    cout << "Yes";
  }else if(mark[0][2] == true && mark[1][1] == true && mark[2][0] == true){
    cout << "Yes";
  }else if(mark[0][0] == true && mark[0][1] == true && mark[0][2] == true){
    cout << "Yes";
  }else if(mark[1][0] == true && mark[1][1] == true && mark[1][2] == true){
    cout << "Yes";
  }else if(mark[2][0] == true && mark[2][1] == true && mark[2][2] == true){
    cout << "Yes";
  }else if(mark[0][0] == true && mark[1][0] == true && mark[2][0] == true){
    cout << "Yes";
  }else if(mark[0][1] == true && mark[1][1] == true && mark[2][1] == true){
    cout << "Yes";
  }else if(mark[0][2] == true && mark[1][2] == true && mark[2][2] == true){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
