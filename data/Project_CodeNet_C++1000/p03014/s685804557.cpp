#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  char a[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  int l[h][w],r[h][w],u[h][w],d[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#') l[i][j]=0;
      else if(j==0) l[i][j]=1;
      else l[i][j]=l[i][j-1]+1;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=w-1;j>=0;j--){
      if(a[i][j]=='#') r[i][j]=0;
      else if(j==w-1) r[i][j]=1;
      else r[i][j]=r[i][j+1]+1;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#') d[i][j]=0;
      else if(i==0) d[i][j]=1;
      else d[i][j]=d[i-1][j]+1;
    }
  }
  for(int i=h-1;i>=0;i--){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#') u[i][j]=0;
      else if(i==h-1) u[i][j]=1;
      else u[i][j]=u[i+1][j]+1;
    }
  }
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ans=max(ans,l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
    }
  }
  cout<<ans<<endl;
  
  /*int b[h][w];
  int c[h][w];
  for(int i=0;i<h;i++){
    int d=-1;
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
        for(int k=d+1;k<j;k++){
          b[i][k]=j-d-1;
        }
        b[i][j]=0;
        d=j;
      }
    }
    for(int j=d+1;j<w;j++){
      b[i][j]=w-d-1;
    }
  }
  
  for(int i=0;i<w;i++){
    int d=-1;
    for(int j=0;j<h;j++){
      if(a[j][i]=='#'){
        for(int k=d+1;k<j;k++){
          c[k][i]=j-d-1;
        }
        c[j][i]=0;
        d=j;
      }
    }
    for(int j=d+1;j<h;j++){
      c[j][i]=h-d-1;
    }
  }
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ans=max(ans,b[i][j]+c[i][j]);
    }
  }
  cout<<ans-1<<endl;*/
}
