#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> a[i][j];
    }
  }
  int n;
  cin >> n;
  vector<vector<bool>>judge(3,vector<bool>(3,false));
  for(int i=0;i<n;i++){
    int b;
    cin >> b;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(a[i][j]==b){
          judge[i][j]=true;
        }
      }
    }
  }
  bool ans=false;
  for(int i=0;i<3;i++){
    if(judge[0][i]&&judge[1][i]&&judge[2][i]){
      ans=true;
    }
    if(judge[i][0]&&judge[i][1]&&judge[i][2]){
      ans=true;
    }
  }
  if(judge[0][0]&&judge[1][1]&&judge[2][2]){
    ans=true;
  }
  if(judge[0][2]&&judge[1][1]&&judge[2][0]){
    ans = true;
  }
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
  
