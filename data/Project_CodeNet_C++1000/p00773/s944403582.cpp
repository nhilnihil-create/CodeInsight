#include <iostream>
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
int x,y,s,ans,a,b,aoff,boff;
int main() {
  while(true){
    cin >> x >> y >> s;
    if(x==0&&y==0&&s==0) return 0;
    ans = 0;
    REP(i,1,s/2+1){
      a = i;
      b = s-i;
      aoff = a*100/(100+x)-1;
      rep(j,3){
        if(aoff*(100+x)/100==a) break;
        aoff++;
      }
      if(aoff*(100+x)/100!=a) continue;
      boff = b*100/(100+x)-1;
      rep(j,3){
        if(boff*(100+x)/100==b) break;
        boff++;
      }
      if(boff*(100+x)/100!=b) continue;
      int on = aoff*(100+y)/100+boff*(100+y)/100;
      if(on>ans) ans = on;
    }
    cout << ans << endl;
  }
  return 0;
}