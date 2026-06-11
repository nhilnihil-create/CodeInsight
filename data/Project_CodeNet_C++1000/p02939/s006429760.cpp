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
#include <set>
using namespace std;
using ll = long long;
 
int main(){
  string S;
  cin >> S;
  int size_S=S.size();
  if(size_S==1){
    cout << 1 << endl;
    return 0;
  }
  
  vector<vector<pair<int,string>>> DP(size_S,vector<pair<int,string>>(2));
  DP.at(0).at(0)=make_pair(1,S.at(0));
  DP.at(0).at(1)=make_pair(1,S.substr(0,2));
  DP.at(1).at(0).second=S.substr(1,1);
  DP.at(1).at(1).second=S.substr(1,2);
  if(DP.at(1).at(0).second!=DP.at(0).at(0).second){
    DP.at(1).at(0).first=2;
  }
  else DP.at(1).at(0).first=0;
  DP.at(1).at(1).first=DP.at(0).at(0).first+1;


  for(int i=2;i<size_S;++i){
    DP.at(i).at(0).second=S.substr(i,1);
    DP.at(i).at(1).second=S.substr(i,2);
    //1 char
    if(DP.at(i).at(0).second!=DP.at(i-1).at(0).second){
      DP.at(i).at(0).first=max(DP.at(i-1).at(0).first+1,DP.at(i-2).at(1).first+1);
    }
    else{
      DP.at(i).at(0).first=DP.at(i-2).at(1).first+1;
    }
    //2 char
    if(DP.at(i).at(1).second!=DP.at(i-2).at(1).second){
      DP.at(i).at(1).first=max(DP.at(i-1).at(0).first+1,DP.at(i-2).at(1).first+1);
    }
    else{
      DP.at(i).at(1).first=DP.at(i-1).at(0).first+1;
    }
  }

  cout << max(DP.at(size_S-1).at(0).first,DP.at(size_S-2).at(1).first) << endl;

  return 0;
}
