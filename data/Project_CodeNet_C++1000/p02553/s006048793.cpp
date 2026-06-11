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

int main(){
  lint a,b,c,d;
  cin>>a>>b>>c>>d;
  lint ans=-2e18;
  ans=max(ans,a*c);
  ans=max(ans,a*d);
  ans=max(ans,b*c);
  ans=max(ans,b*d);
  cout<<ans<<endl;
  return 0;
}
