#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)

bool	check(int dist){
  bool ok=false;
  for(int i=0;i*i<=dist;i++){
    if(i*i==dist)	ok=true;
  }
  return ok;
}

int main(){
  int n,d;	cin >> n >> d;
  vector<vector<int>>	X(n,vector<int>(d));
  rep(i,n){
    rep(j,d){
      cin >> X[i][j];
    }
  }
  
  auto	dist=[&](int i,int j){
    int kyori=0;
    for(int k=0;k<d;k++){
      kyori+=(X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
    }
    return kyori;
  };
  
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int x=dist(i,j);
      if(check(x))	ans++;
    }
  }
  cout << ans;
}