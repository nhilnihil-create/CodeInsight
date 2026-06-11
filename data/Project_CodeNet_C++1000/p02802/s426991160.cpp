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
  int N,M;
  cin >> N >> M;
  vector<pair<bool,int>> prob(N,make_pair(false,0));
  int p;
  string s;
  int ac=0,pena=0;
  for(int i=0;i<M;++i){
    cin >> p >> s;
    --p;
    if(s=="WA") prob.at(p).second++;
    else{
      if(prob.at(p).first==true) continue;
      else{
	prob.at(p).first=true;
	++ac;
	pena+=prob.at(p).second;
      }
    }
  }

  cout << ac << " " << pena << endl;

  return 0;
}
