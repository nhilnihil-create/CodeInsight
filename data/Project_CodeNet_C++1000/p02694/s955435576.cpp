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
  LL x,count=0,money=100;
  cin >> x;
  
  while(money < x){
    money += money/100;
    count++;
  }
  
  cout << count << endl;
  
  return 0;
}
