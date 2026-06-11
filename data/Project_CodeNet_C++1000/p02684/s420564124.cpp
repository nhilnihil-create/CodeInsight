#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
const int INF = 0x7fffffff;
using lll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
  lll ii,jj,kk;
  vector<int> ret;
  lll n,k;

  cin >> n >> k;

  vector<int> a(n);
  vector<int> root;
  set<int> s;
  for(ii=0;ii<n;ii++){
    cin >> a[ii];
    //cout << a[ii] << endl;
  }

  int pos = 0;
  root.push_back(pos);
  s.insert(pos);
  
  while(true){
    pos = a[pos] -1;
    //cout << pos << "->" ;

    if(s.find(pos) != s.end()){
      root.push_back(pos);
      break;
    }
    else{
      root.push_back(pos);
      s.insert(pos);
    }

  }

  //for(ii=0;ii<root.size();ii++){
  //  cout << root[ii] << "->";
  //}
  //cout << endl;
  
  int last = root[root.size()-1];
  //cout << "last:" << last << endl;
  lll loopNum=0;
  lll loopStart = 0;
  for(ii=root.size()-2;ii>=0;ii--){
    //cout << root[ii] << "->" ;

    if(last == root[ii]){
      loopNum++;
      loopStart = ii;
      //cout << endl;
      break;
    }
    else{
      loopNum++;
    }
    
  }

  //cout << "loopStart:"  << loopStart << endl;
  //cout << "loopNum:" << loopNum << endl;
  lll lastPos;
  lll ans;
  if(loopStart >= k){
    ans = root[k] + 1;
  }
  else{
    lll startPos;
    startPos = k - loopStart;
    lll goNum = startPos % loopNum;

    ans = root[loopStart+goNum] + 1;
    //for(ii=loopStart;ii<goNum;ii++){
    //  
    //}
  }

  cout << ans << endl;
  return 0;
}
