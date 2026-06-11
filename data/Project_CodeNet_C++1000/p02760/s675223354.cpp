#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3][3],n;
  int ok[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++) cin >> a[i][j];    
  }
  
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++) ok[i][j] = 0;
  }

  cin >> n;
  for(int z=0;z<n;z++){
    int b;
    cin >> b;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(a[i][j] == b){
          ok[i][j] = 1;
        }
      }
    }
  }
    
  string ans = "No";
  for(int i=0;i<3;i++){
    if(ok[i][0] == 1 && ok[i][1] == 1 && ok[i][2] == 1) ans = "Yes";
  }
  for(int i=0;i<3;i++){  
    if(ok[0][i] == 1 && ok[1][i] == 1 && ok[2][i] == 1) ans = "Yes";
  }
  if(ok[0][0] == 1 && ok[1][1] == 1 && ok[2][2] == 1) ans = "Yes";
  if(ok[0][2] == 1 && ok[1][1] == 1 && ok[2][0] == 1) ans = "Yes";
  cout << ans << endl;
  return 0;
}