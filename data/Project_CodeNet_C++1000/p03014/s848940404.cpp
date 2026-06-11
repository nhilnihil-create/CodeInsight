#include<bits/stdc++.h>
using namespace std;

int L[2010][2010],R[2010][2010],D[2010][2010],U[2010][2010];

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i=0;i<h;++i){
    cin >> s[i];
  }
  //int L[2010][2010],R[2010][2010],D[2010][2010],U[2010][2010];
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(s[i][j]=='#'){
        L[i][j]=0;
      }else{
        if(j==0){
          L[i][j]=1;
        }else{
          L[i][j]=L[i][j-1]+1;
        }
      }
    }
  }
  for(int i=0;i<h;++i){
    for(int j=w-1;j>=0;--j){
      if(s[i][j]=='#'){
        R[i][j]=0;
      }else{
        if(j==w-1){
          R[i][j]=1;
        }else{
          R[i][j]=R[i][j+1]+1;
        }
      }
    }
  }
  for(int i=0;i<w;++i){
    for(int j=0;j<h;++j){
      if(s[j][i]=='#'){
        D[j][i]=0;
      }else{
        if(j==0){
          D[j][i]=1;
        }else{
          D[j][i]=D[j-1][i]+1;
        }
      }
    }
  }
  for(int i=0;i<w;++i){
    for(int j=h-1;j>=0;--j){
      if(s[j][i]=='#'){
        U[j][i]=0;
      }else{
        if(j==h-1){
          U[j][i]=1;
        }else{
          U[j][i]=U[j+1][i]+1;
        }
      }
    }
  }
  int ans=0;
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      ans=max(ans,L[i][j]+R[i][j]+D[i][j]+U[i][j]-3);
    }
  }
  cout << ans << endl;
  return 0;
}
