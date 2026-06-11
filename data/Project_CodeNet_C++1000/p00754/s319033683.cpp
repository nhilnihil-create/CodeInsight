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
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  string s;
  while(getline(cin, s) && s!= "."){
    bool ok = true;
    stack<char> stk;
    REP(i, s.size()){
      if(s[i] == '(' || s[i] == '['){
        stk.push(s[i]);
      }else if(s[i] == ')' || s[i] == ']'){
        if(stk.empty()){
          ok = false;
          break;
        }
        char t = stk.top(); stk.pop();
        if(t == '(' && s[i] == ']'){
          ok = false;
           break;
        }
        if(t == '[' && s[i] == ')'){
          ok = false;
           break;
        }
      }
    }
    if(ok && stk.empty()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }

  return 0;
}