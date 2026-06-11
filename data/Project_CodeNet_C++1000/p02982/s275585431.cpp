#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int N,D;
  cin >> N >> D;
  vector<vector<int>> X(N,vector<int>(D));

  for(int i=0;i<N;++i){
    for(int j=0;j<D;++j) cin >> X.at(i).at(j);
  }

  int ans=0;
  
  for(int i=0;i<N;++i){
    for(int j=i+1;j<N;++j){
      double sum=0;
      for(int d=0;d<D;++d) sum+=pow(X.at(i).at(d)-X.at(j).at(d),2);
      sum=sqrt(sum);
      if(sum==(int)sum) ++ans;
    }  
  }

  cout << ans << endl;

  return 0;
}
