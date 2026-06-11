#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  vector<vector<int> > edge(N);
  int u, v;
  for(int i=0;i<M;++i){
    cin>>u>>v;
    u--;
    v--;
    edge[u].push_back(v);
  }
  int S, T;
  cin>>S>>T;
  S--;
  T--;
  queue<int> que;
  queue<int> numque;
  map<int, vector<int> > amap;
  bool ok[N];
  que.push(S);
  numque.push(0);
  int state, num;
  bool aru;
  while(!que.empty()){
    state = que.front();que.pop();
    num = numque.front();numque.pop();
    aru = false;
    for(int i=0;i<amap[state].size();++i){
      if(amap[state][i]%3==num%3) aru = true;
    }
    if(aru) continue;
    amap[state].push_back(num);
    for(int i=0;i<edge[state].size();++i){
      aru = false;
      for(int j=0;j<amap[edge[state][i]].size();++j){
        if(amap[edge[state][i]][j]%3==(num+1)%3) aru = true;
      }
      if(aru) continue;
      que.push(edge[state][i]);
      numque.push(num+1);
    }
  }
  int ans = -1;
  aru = false;
  for(int i=0;i<amap[T].size();++i){
    if(amap[T][i]%3==0) {
      ans = amap[T][i];
      aru = true;
    }
  }
  if(aru) cout<<ans/3<<endl;
  else cout<<-1<<endl;
}

