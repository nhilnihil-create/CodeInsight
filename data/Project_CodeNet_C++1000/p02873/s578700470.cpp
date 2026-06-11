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
  string S;
  cin >> S;
  int n=S.size();
  vector<pair<int,int>> v(n+1,make_pair(0,0));
  ll ans=0;
  for(int i=0;i<n;++i){
    if(S.at(i)=='<') v.at(i+1).first=v.at(i).first+1;
  }
  for(int i=n-1;i>=0;--i){
    if(S.at(i)=='>') v.at(i).second=v.at(i+1).second+1;
  }
  
  for(int i=0;i<n+1;++i) ans+=max(v.at(i).first,v.at(i).second);
  
  cout << ans << endl;

  return 0;
}
