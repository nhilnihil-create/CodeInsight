#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
bool solve(string str){
  map<char, int> t;
  t['['] = 1; t[']'] = 1;
  t['('] = 2; t[')'] = 2;
  stack<char> stk;
  REP(i,str.size()){
    if(str[i]=='['||str[i]=='('){
      stk.push(t[str[i]]);
    }else if(str[i]==']'||str[i]==')'){
      if(stk.empty()||stk.top()!=t[str[i]]) return false;
      else stk.pop();
    }
  }
  return stk.empty();
}
int main(){
  string str;
  while(getline(cin,str)){
    if(str==".") break;
    if(solve(str)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}