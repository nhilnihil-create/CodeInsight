#include<bits/stdc++.h>
using namespace std;

int main(){
  int b[3][3];
  bool f[3][3];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> b[i][j];
      f[i][j] = false;
    }
  }
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    for(int k = 0; k < 3; k++){
      for(int l = 0; l < 3; l++){
        if(a == b[k][l]){
          f[k][l] = true;
        }
      }
    }
  }
  if((f[0][0]&&f[0][1]&&f[0][2])||(f[1][0]&&f[1][1]&&f[1][2])||(f[2][0]&&f[2][1]&&f[2][2])
     ||(f[0][0]&&f[1][0]&&f[2][0])||(f[0][1]&&f[1][1]&&f[2][1])||(f[0][2]&&f[1][2]&&f[2][2])
    ||(f[0][0]&&f[1][1]&&f[2][2])||(f[2][0]&&f[1][1]&&f[0][2])){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}