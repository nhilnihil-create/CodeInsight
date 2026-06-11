#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin>>n>>d;
  vector<vector<int>>a(n,vector<int>(d));
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++){
      cin>>a[i][j];
    }
  }
  int kotae=0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      int kyori=0;
      for(int k=0;k<d;k++){
        kyori+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
      }
      int kazu=sqrt(kyori);
      if(kazu*kazu==kyori)kotae++;
    }
  }
  cout<<kotae<<endl;
  return 0;
}


