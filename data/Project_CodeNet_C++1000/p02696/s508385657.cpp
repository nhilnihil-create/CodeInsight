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
using VB = vector<bool>;
using VVB = vector<VB>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(int i=(m);i>=(n);i--)
	//i=m -> n(降順)

int main(){
  LL a,b,n,ans;
  cin >> a >> b >> n;
  
  if(b > n){
    ans = ((a*n)/b) - a*(n/b);
  }
  else if(b == 1){
    ans = 0;
  }
  else{
    ans = a-1-(a/b);
  }
  
  cout << ans << endl;
  
  return 0;
}
