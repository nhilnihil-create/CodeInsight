#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;
lint p=1e9+7;

lint mod_pow(lint a,int n,lint p){
  lint r=1;
  REP(i,n){
    r*=a;
    r%=p;
  }
  return r;
}

int main(){
  int N;
  cin>>N;
  lint ans=mod_pow(10,N,p);
  ans-=mod_pow(9,N,p);
  if(ans<0)ans+=p;
  ans-=mod_pow(9,N,p);
  if(ans<0)ans+=p;
  ans+=mod_pow(8,N,p);
  ans%=p;
  cout<<ans<<endl;
  return 0;
}
