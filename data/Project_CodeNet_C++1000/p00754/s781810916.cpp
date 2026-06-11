#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define dbg(x) cout<<#x"="<<x<<endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define INF 1000000000

enum {NONE, SQ, RD}; //last bracket (square or round)
bool solve(char *l){
  int idx=0;
  stack<int> st;
  while(true){
    switch(l[idx]){
    case '(':
      st.push(RD);
      break;
    case '[':
      st.push(SQ);
      break;
    case ')':
      if(st.empty() || st.top()!=RD) return false;
      else st.pop();
      break;
    case ']':
      if(st.empty() || st.top()!=SQ) return false;
      else st.pop();
      break;
    case '.':
      if(st.empty()) return true;
      else return false;
      break;
    }
    idx++;      
  }


}

int main(){
  while(true){
    char l[128];
    scanf("%[^\n]", l);
    if(l[0]=='.') break;
    getchar(); // read \n

    if(solve(l)) cout << "yes" << endl;
    else cout << "no" << endl;

  }

}