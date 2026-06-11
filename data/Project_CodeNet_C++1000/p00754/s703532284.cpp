#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
// stack
int main()
{
  string s;
  while(getline(cin, s)) {
    if(s[0] == '.' && s.length() == 1) return 0;
    stack<char> st;
    bool ok = true;
    FOR(i,0,s.length()) {
      if(s[i] == '(' || s[i] == '[') st.push(s[i]);
      if(s[i] == ')' || s[i] == ']') {
        if(st.empty()) {
          ok = false;
          break;
        }
        char c = st.top(); st.pop();
        if(s[i] == ')' && c == '[') {
          ok = false;
          break;
        }
        if(s[i] == ']' && c == '(') {
          ok = false;
          break;
        }
      }
    }
    if(!st.empty()) ok = false;
    puts(ok?"yes":"no");
  }
  return 0;
}