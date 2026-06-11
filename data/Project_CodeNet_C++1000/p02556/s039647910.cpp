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
  int N;
  cin>>N;
  pair<int,int> a[4];
  REP(i,N){
    int x,y;
    cin>>x>>y;
    if(i==0){
      REP(j,4)a[j]=make_pair(x,y);
    }else{
      REP(j,4){
        auto& X=a[j].first;
        auto& Y=a[j].second;
        int s1=(j>=2?-1:1);
        int s2=(j%2?-1:1);
        if(s1*(x+s2*y)>s1*(X+s2*Y))a[j]=make_pair(x,y);
      }
    }
  }
  int ans=0;
  REP(i,4)cerr<<a[i].first<<","<<a[i].second<<endl;
  REP(i,4)REP(j,4){
    auto dx=a[i].first-a[j].first;
    auto dy=a[i].second-a[j].second;
    ans=max(ans,max(dx,-dx)+max(dy,-dy));
  }
  cout<<ans<<endl;
  return 0;
}
