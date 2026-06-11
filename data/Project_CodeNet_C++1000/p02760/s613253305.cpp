#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a[3][3];
  bool po[3][3] = {false};
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> a[i][j];
    }
  }
  
  int n;
  cin >> n;
  int b[n];
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }
  
  for(int k = 0; k < n; k++){
   for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(b[k] == a[i][j]){
        po[i][j] = true;
      }//if
    }//for
   }//for
  }//for
     
  for(int i = 0; i < 3; i++){
    if(po[i][0] && po[i][1] && po[i][2]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  for(int j = 0; j < 3; j++){
    if(po[0][j] && po[1][j] && po[2][j]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  if(po[0][0] && po[1][1] && po[2][2]){
    cout << "Yes" << endl;
    return 0;
  }
  if(po[0][2] && po[1][1] && po[2][0]){
    cout << "Yes" << endl;
    return 0;
  }
  
  cout << "No" << endl;
  
   }