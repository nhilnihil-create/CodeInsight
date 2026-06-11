#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using PLL = pair<LL,LL>;
using VPI = vector<PII>;
using VPL = vector<PLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define RREP(i,m,n) for(int i=(m);i>=(n);i--)

int main(){
  int s,w;
  cin >> s >> w;
  
  if(w >= s){
    cout << "unsafe" << endl;
  }
  else{
    cout << "safe" << endl;
  }
  
  return 0;
}
