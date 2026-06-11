#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int H,W,K;
  cin>>H>>W>>K;
  
  string S[H];
  for(int i=0;i<H;i++){
    cin>>S[i];
  }
  
  int ans=0;
  
  
  for(int i=0;i<((1<<H)-1);i++){
    for(int j=0;j<((1<<W)-1);j++){
      int check=0;
      for(int l=0;l<H;l++){
        for(int m=0;m<W;m++){
          if(((i>>l)&1)==0&&((j>>m)&1)==0&&S[l][m]=='#'){
            check++;
          }
        }
      }
      if(check==K){
        ans++;
      }
    }
  }
  
  cout<<ans<<endl;
}