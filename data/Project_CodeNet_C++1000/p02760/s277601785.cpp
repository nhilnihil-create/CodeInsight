#include <bits/stdc++.h>
using namespace std;

int main(){
  int A[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++) cin>>A[i][j];
  }
  bool ans[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++) ans[i][j]=false;
  }
  int N;cin>>N;
  for(int i=0;i<N;i++){
    int b;cin>>b;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(A[i][j]==b) ans[i][j]=true;
      }
    }
  }
  bool can=false;
  for(int i=0;i<3;i++){
    if(ans[i][0] && ans[i][1] && ans[i][2]) can=true;
  }
  for(int i=0;i<3;i++){
    if(ans[0][i] && ans[1][i] && ans[2][i]) can=true;
  }
  if(ans[0][0] && ans[1][1] && ans[2][2]) can=true;
  if(ans[2][0] && ans[1][1] && ans[0][2]) can=true;
  cout<<(can?"Yes":"No")<<endl;
}
