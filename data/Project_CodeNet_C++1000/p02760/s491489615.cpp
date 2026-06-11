#include<bits/stdc++.h>
using namespace std;

int main(){
  int num[3][3], check[3][3] = {};
  for(int i =0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> num[i][j];
    }
  }
  int n, tmp;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> tmp;
    for(int j = 0;j<3;j++){
      for(int k = 0;k <3;k++){
        if(num[j][k] == tmp){
          check[j][k] = 1;
        }
      }
    }
  }
  string ANS ="No";
  for(int i =0;i<3;i++){
    if(check[i][0] == 1 && check[i][1] == 1 && check[i][2] == 1)
      ANS = "Yes" ;
  }
  for(int i =0;i<3;i++){
    if(check[0][i] == 1 && check[1][i] == 1 && check[2][i] == 1)
      ANS = "Yes" ;
  }
  if(check[0][0] == 1 && check[1][1] == 1 && check[2][2] == 1)
    ANS = "Yes" ;
  if(check[0][2] == 1 && check[1][1] == 1 && check[2][0] == 1)
    ANS = "Yes" ;
  cout << ANS << endl;
}