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


  lll n;

  cin >> n;
  
 lll ret;  
  ret = n;

  vector<lll> temp;
  

  while(ret != 0){

    if(ret % 26 == 0){
      temp.push_back(26);
      ret -= 1;
    }
    else{
      temp.push_back(ret % 26);
    }

    ret = ret / 26;
    
  }
  string res;
  for(ii=temp.size()-1;ii>=0;ii--){
    //cout << temp[ii] << "," ;
    //if(temp[ii] != 0){
      res += 'a' + temp[ii] - 1;
      //}
    //else{
    //  res += 'z';
    //}
  }
  //cout << endl;
  
  cout << res << endl;
  return 0;
}
