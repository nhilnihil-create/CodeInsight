#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,A,B;
  cin>>H>>W>>A>>B;
  int D[W][H];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if((j<=A-1 && i<=B-1)||(j>=A && i>=B)){
        D[j][i]=0;
      }
      else D[j][i]=1;
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout<<D[j][i];
    }
    cout<<endl;
  }  
  cout<<endl;  
  return 0;
}

  