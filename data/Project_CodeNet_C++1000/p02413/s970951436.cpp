#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  int h,w;
  cin>>h>>w;
  vector<vector<int> > hw(h+1,vector<int>(w+1,0));
  int all=0;
  for(int i=0;i<h;i++){
    int tmp=0;
    for(int j=0;j<w;j++){
      cin>>hw[i][j];
      tmp+=hw[i][j];
      all+=hw[i][j];
    }
    hw[i][w]=tmp;
  }
  hw[h][w]=all;
  for(int i=0;i<w;i++){
    int tmp=0;
    for(int j=0;j<h;j++){
      tmp+=hw[j][i];
    }
    hw[h][i]=tmp;
  }

  for(int i=0;i<h+1;i++){
    for(int j=0;j<w+1;j++){
      cout<<hw[i][j];
      if(j!=w)cout<<" ";
    }
    cout<<endl;
  }
}

