#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x;
  cin >>x;
  int kazu=x/100;
  int amari=x%100;
  for(int i=0;i<=kazu;i++){
    for(int j=0;j<=kazu;j++){
      for(int k=0;k<=kazu;k++){
        for(int m=0;m<=kazu;m++){
          for(int n=0;n<=kazu;n++){
            if(i+j*2+k*3+m*4+n*5==amari&&i+j+k+m+n<=kazu){
              cout<<1<<endl;
              return 0;
            }
            if(i+j+k+m+n>kazu)break;
          }
        }
      }
    }
  }
  cout<<0<<endl;
  return 0;
}
