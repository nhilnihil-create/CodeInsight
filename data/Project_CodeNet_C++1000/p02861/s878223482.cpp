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
  int N;
  cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  double dist=0;
  for(int i=0;i<N;++i){
    cin >> x.at(i) >> y.at(i);
  }

  for(int i=0;i<N;++i){
    for(int j=i;j<N;++j){
      dist+=sqrt(pow(x.at(i)-x.at(j),2)+pow(y.at(i)-y.at(j),2));
    }
  }
  
  dist=dist*2/N;

  printf("%.10f\n",dist);

  return 0;
}
