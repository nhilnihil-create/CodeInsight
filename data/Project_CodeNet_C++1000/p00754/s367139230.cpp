#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define mod 1000000007 //1e9+7
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 201

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool calc(){
  char s[SIZE];
  stack<char> st;
  
  scanf("%[^\n]%*[\n]",s);

  if(s[0]=='.') return false;
  
  for(int i=0;s[i]!='.';i++){
    if(s[i]=='[' || s[i]=='(') st.push(s[i]);
    if(s[i]==']'){
      if(st.empty() || st.top()!='['){
	puts("no");
	return true;
      }
      st.pop();
    }
    if(s[i]==')'){
      if(st.empty() || st.top()!='('){
	puts("no");
	return true;
      }
      st.pop();
    }
  }

  if(st.empty()) puts("yes");
  else puts("no");
  
  return true;
}

int main(){
  
  while(calc());
  
  return 0;
}