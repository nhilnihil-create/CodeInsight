#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;

int H,W;
void solve(){
  ll defT=H*H+W*W;
  vector<ppi> v;
  for(int i=1;i<=1000;i++){
    for(int j=1;j<=1000;j++){
      if(j>i){
        ll T=i*i+j*j;
        v.push_back(make_pair(pii(T,i),j));
      }
    }
  }
  //v.push_back(make_pair(pii(defT,H),W));
  sort(v.begin(),v.end());
  for(int i=0;i<(int)v.size();i++){
    if(v[i].first.second==H&&v[i].second==W){
      cout<<v[i+1].first.second<<" "<<v[i+1].second<<endl;
      return;
    }
  }
}

int main(){

  while(cin>>H>>W&&(H|W)){
    solve();
  }
  
  return 0;
}