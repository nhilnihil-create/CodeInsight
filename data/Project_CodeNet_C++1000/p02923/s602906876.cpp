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
  vector<ll> H(N+1);
  H.at(0)=0;

  int ans=0;
  int temp_ans=0;
  for(int i=0;i<N;++i){
    cin >> H.at(i+1);
    if(H.at(i)>=H.at(i+1)){
      ++temp_ans;
    }
    else{
      ans=max(ans,temp_ans);
      temp_ans=0;
    }
  }

  ans=max(ans,temp_ans);

  cout << ans << endl;

  return 0;
}
