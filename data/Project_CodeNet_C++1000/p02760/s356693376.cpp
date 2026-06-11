#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
  int a[3][3];
  int b,c;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> a[i][j];
    }
  }
  cin >> b;
  for(int k=0;k<b;k++){
    cin >> c;
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(a[i][j]==c)a[i][j]=0;
    }
  }
  }
    bool exist = false;
    for(int i=0;i<3;i++){
      if(a[i][0]==0&&a[i][1]==0&&a[i][2]==0)exist = true;
    }
    for(int i=0;i<3;i++){
      if(a[0][i]==0&&a[1][i]==0&&a[2][i]==0)exist = true;
    }
    if(a[0][0]==0&&a[1][1]==0&&a[2][2]==0)exist=true;
    if(a[0][2]==0&&a[1][1]==0&&a[2][0]==0)exist=true;
    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}