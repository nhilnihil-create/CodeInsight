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
#define REP(i,m,n) for(int i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(int i=(m);i>=(n);i--)
	//i=m -> n(降順)

int main(){
  int n,ans=0;
  cin >> n;
  VI a(n);
  REP(i,0,n){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  VB div(a[n-1]+1,true);
  
  REP(i,0,n){
    if(i != n-1){
      if(a[i] == a[i+1]){
        div[a[i]] = false;
      }
    }
    for(int j=2*a[i]; j<=a[n-1]; j+=a[i]){
      if(div[j]){div[j] = false;}
    }
  }
  
  REP(i,0,n){
    if(div[a[i]]){ans++;}
  }
  
  cout << ans << endl;
  
  return 0;
}
