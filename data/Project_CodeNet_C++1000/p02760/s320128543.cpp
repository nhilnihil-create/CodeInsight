#include <bits/stdc++.h>
using namespace std;

int main() {
  int num[3][3]; //番号
  bool isHole[3][3]; //穴があいてるか
  
  //入力
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      isHole[i][j] = false;
    }
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin>>num[i][j];
    }
  }
  
  //でた番号の配列
  int N;
  cin>>N;
  int b[N];
  for(int i=0; i<N; i++){
    cin>>b[i];
  }
  
  
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      for(int x=0; x<N; x++){
        if(num[i][j] == b[x]){
          isHole[i][j] = true;
          break;
        }
      }
    }
  }
  bool ans = false;
  if(isHole[0][0] && isHole[0][1] && isHole[0][2]) ans=true;
  else if(isHole[1][0] && isHole[1][1] && isHole[1][2]) ans=true;
  else if(isHole[2][0] && isHole[2][1] && isHole[2][2]) ans=true;
  else if(isHole[0][0] && isHole[1][0] && isHole[2][0]) ans=true;
  else if(isHole[0][1] && isHole[1][1] && isHole[2][1]) ans=true;
  else if(isHole[0][2] && isHole[1][2] && isHole[2][2]) ans=true;
  else if(isHole[0][0] && isHole[1][1] && isHole[2][2]) ans=true;
  else if(isHole[0][2] && isHole[1][1] && isHole[2][0]) ans=true;
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}