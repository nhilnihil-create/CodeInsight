#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin >> n;

  int mm[201][201];
  for(int i=1;i<201;i++){
    for(int j=1;j<201;j++){
      int I = i; int J = j;
      if(J<I){int temp=I; I=J; J=temp;}
      while(true){
        int templ = J;
        J = I % J;
        I = templ;
        if(J==0){mm[i][j]=I; break;}
        if(J==1){mm[i][j]=J; break;}
      }
    }
  }


  int cnt = 0;
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){
      for(int k=1;k<n+1;k++){
        cnt += mm[mm[i][j]][mm[j][k]];
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
