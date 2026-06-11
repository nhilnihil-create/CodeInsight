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
  vector<int> A(N+1);
  vector<int> B(N);
  for(int i=0;i<N+1;++i) cin >> A.at(i);
  for(int i=0;i<N;++i) cin >> B.at(i);

  ll ans=0;
  for(int i=0;i<N;++i){
    if(A.at(i)<B.at(i)){
      ans+=A.at(i);
      B.at(i)-=A.at(i);
      A.at(i)=0;
      if(A.at(i+1)<B.at(i)){
	ans+=A.at(i+1);
	B.at(i)-=A.at(i+1);
	A.at(i+1)=0;
      }
      else{
	ans+=B.at(i);
	A.at(i+1)-=B.at(i);
	B.at(i)=0;
      }
    }
    else{
      ans+=B.at(i);
      A.at(i)-=B.at(i);
      B.at(i)=0;
    }
  }

  cout << ans << endl;

  return 0;
}
