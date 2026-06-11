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
  int N,Q;
  cin>>N>>Q;
  vector<int> c[N];
  REP(i,N-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    c[a].push_back(b);
    c[b].push_back(a);
  }
  lint ans[N];
  REP(i,N)ans[i]=0;
  REP(i,Q){
    int p;
    lint x;
    cin>>p>>x;
    p--;
    ans[p]+=x;
  }
  queue<int> q;
  q.push(0);
  int d[N];
  REP(i,N)d[i]=0;
  d[0]=1;
  while(!q.empty()){
    int p=q.front();
    q.pop();
    for(auto e:c[p]){
      if(d[e])continue;
      d[e]=1;
      ans[e]+=ans[p];
      q.push(e);
    }
  }
  REP(i,N){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}
