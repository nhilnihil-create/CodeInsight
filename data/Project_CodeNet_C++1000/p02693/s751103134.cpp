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
using VP = vector<PII>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(LL i=(m);i>=(n);i--)
	//i=m -> n(降順)

int main(){
  LL k,a,b;
  cin >> k >> a >> b;
  
  REP(i,a,b+1){
    if(i % k == 0){
      cout << "OK" << endl;
      return 0;
    }
  }
  
  cout << "NG" << endl;
  
  return 0;
}
