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
  vector<int> A(N);
  vector<ll> sum(N,0);
  for(int i=0;i<N;++i){
    cin >> A.at(i);
    if(i==0) sum.at(i)=A.at(i);
    else sum.at(i)=sum.at(i-1)+A.at(i);
  }

  ll ave=sum.at(N-1)/2;
  int left=-1,right=N,mid;
  while(right-left>1){
    mid=(left+right)/2;
    if(sum.at(mid)<ave){
      left=mid;
    }
    else right=mid;
  }

  int ans=0;
  ans=min(abs(sum.at(N-1)-2*sum.at(left)),abs(sum.at(N-1)-2*sum.at(right)));
  
  cout << ans << endl;
  
  return 0;
}
