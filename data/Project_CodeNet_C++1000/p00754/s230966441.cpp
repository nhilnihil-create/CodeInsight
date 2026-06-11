#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

const string op = "[(", cl = "])";

int main(){
  int i,j;
  string in;

  while(1){
    getline(cin,in); // cout << in << endl;
    if(in == ".") break;

    bool f = true;
    int N = in.length();
    stack<char> st;

    REP(i,N) REP(j,2){
      if(in[i] == op[j]) st.push(in[i]);
      if(in[i] == cl[j]){
        if(!st.empty() && op[j] == st.top()) st.pop();
        else f = false;
      }
    }

    if(!st.empty()) f = false;
    cout << ((f) ? "yes" : "no") << endl;
  }

  return 0;
}