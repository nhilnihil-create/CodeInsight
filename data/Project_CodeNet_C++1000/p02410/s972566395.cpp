#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){

  int n,m;
  int a[256][256],b[256];
  int ans[256]={0};
  int i,j;

  cin >>n >>m;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cin >>a[i][j];
    }
  }
  for(i=0;i<m;i++){
    cin >>b[i];
  }

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      ans[i]+=a[i][j]*b[j];
    }
  }

  for(i=0;i<n;i++)
    cout <<ans[i] <<endl;

  return 0;
}