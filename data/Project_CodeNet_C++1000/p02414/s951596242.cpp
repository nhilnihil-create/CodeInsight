#include<iostream>
using namespace std;
int main(){
  int n,m,l;
  long  nm[101][101],ml[101][101],nl[101][101]={};

  cin>>n>>m>>l;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>nm[i][j];
      }
  }    
  for(int i=0;i<m;i++){
    for(int j=0;j<l;j++){
        cin>>ml[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      for(int k=0;k<l;k++){
          nl[i][k]+=nm[i][j]*ml[j][k];
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<l-1;j++){
        cout<<nl[i][j]<<" ";
    }
    cout<<nl[i][l-1]<<endl;
  }
  return 0;
}

