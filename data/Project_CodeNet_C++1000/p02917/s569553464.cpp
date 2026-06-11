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
  vector<ll> A(N);
  vector<ll> B(N-1);
  for(int i=0;i<N-1;++i) cin >> B.at(i);

  ll ans=0;
  A.at(N-1)=B.at(N-2);
  for(int i=N-2;i>=0;--i){
    A.at(i)=B.at(i);
    A.at(i+1)=min(B.at(i),A.at(i+1));
  }

  for(int i=0;i<N;++i){
    ans+=A.at(i);
    //cout << A.at(i) << " ";
  }
  //cout << endl;

  cout << ans << endl;

  return 0;
}
