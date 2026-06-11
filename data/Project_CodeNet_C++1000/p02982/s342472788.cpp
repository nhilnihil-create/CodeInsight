#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin>>n>>d;
  int x[n][d];
  for(int i=0;i<n;i++){
      for(int j=0;j<d;j++){
          cin>>x[i][j];
      }
  }
  int num=0;
  for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          int su=0;
          for(int k=0;k<d;k++){
              su+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
          }
          int dus=sqrt(su);
          if(dus*dus==su) num++;
      }
  }
  cout<<num<<endl;
}