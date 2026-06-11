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
  vector<pair<bool,int>> H(N,make_pair(false,0));

  string ans="Yes";
  for(int i=0;i<N;++i) cin >> H.at(i).second;
  for(int i=N-1;i>0;--i){
    if(H.at(i).second>=H.at(i-1).second) continue;
    else if(H.at(i-1).second-H.at(i).second!=1){
      ans="No";
      break;
    }
    else{
      H.at(i-1).second--;
      H.at(i-1).first=true;
    }
  }

  cout << ans << endl;
  
  return 0;
}
