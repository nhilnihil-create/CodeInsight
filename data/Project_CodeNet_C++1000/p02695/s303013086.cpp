#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
#include <stack>
#include <iomanip>
#include <limits>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
using Graph=vector<vector<int>>;
using edge= struct{int to;ll cost;};
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
typedef priority_queue<ll> PQ_HIGH;
typedef priority_queue<ll,VL,greater<ll>> PQ_LOW;//昇順

void test(priority_queue<pair<ll,ll>> que){
  while(!que.empty()){
    cout<<que.top().first<<" "<<que.top().second<<endl;
    que.pop();
  }
}
int n,m,q;

vector<int> a,b,c,d;
vector<ll> e(10,0);
ll ma=0;

void dfs(int position,int num){
  e[position]=num;
  if(position>=n){
    ll alpha=0;
    for(int i=0;i<q;i++){
      int tmp;
      tmp=e[b[i]]-e[a[i]];
      if(tmp==c[i]){
        alpha+=d[i];
      }
    }
    if(alpha>ma){ma=alpha;}
    return;
  }
  for(int i=num;i<=m;i++){
    dfs(position+1,i);
  }
  return;
}

int main(){
  cin>>n>>m>>q;
  int a1,b1,c1,d1;
  REP(i,q){
    cin>>a1>>b1>>c1>>d1;
    a.push_back(a1);
    b.push_back(b1);
    c.push_back(c1);
    d.push_back(d1);
  }
  dfs(0,1);
  cout<<ma<<endl;
}