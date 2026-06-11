#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  int i, j, k, N, D, X[10][10], count=0, sum;
  
  cin >> N >> D;
  
  rep(i,N){
    rep(j,D){
      cin >> X[i][j];
    }
  }
  

  rep(i,N){
    for(j=i+1;j<N;j++){
      sum =0;
      for(k=0; k<D; k++){
        sum += (X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
      }
      for(k=0;k*k<=sum;k++){
        if(sum==k*k){
          count +=1;
          break;
        }
      }
    }
  }
  cout << count;
}


