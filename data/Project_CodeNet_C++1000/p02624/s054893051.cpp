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
  LL n;
  LL ans=0;
  cin >> n;
  VLL f(n+1,2);
  f[1] = 1;
  LL end = n/2;
  
  REP(i,2,end+1){
    for(LL j=i*2; j<=n; j += i){
      f[j]++;
    }
  }
  REP(i,1,n+1){
    ans += i*f[i];
  }
  
  cout << ans << endl;
  
  return 0;
}
