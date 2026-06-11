#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[3][3];
  for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin >> a[i][j];
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(a[i][j]==x)a[i][j]=0;
        }
      }
  }
  if(a[0][0]==0 && a[0][1]==0 && a[0][2]==0)cout << "Yes" << endl;
  else if(a[1][0]==0 && a[1][1]==0 && a[1][2]==0)cout << "Yes" << endl;
  else if(a[2][0]==0 && a[2][1]==0 && a[2][2]==0)cout << "Yes" << endl;
  else if(a[0][0]==0 && a[1][0]==0 && a[2][0]==0)cout << "Yes" << endl;
  else if(a[0][1]==0 && a[1][1]==0 && a[2][1]==0)cout << "Yes" << endl;
  else if(a[0][2]==0 && a[1][2]==0 && a[2][2]==0)cout << "Yes" << endl;
  else if(a[0][0]==0 && a[1][1]==0 && a[2][2]==0)cout << "Yes" << endl;
  else if(a[0][2]==0 && a[1][1]==0 && a[2][0]==0)cout << "Yes" << endl;
  else cout << "No" << endl;
}