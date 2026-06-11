#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  rep(i,m){
    int a,b;cin >> a >> b;
    a--,b--;
    v[a].push_back(b);
  }
  int S,T;
  cin >> S >> T;
  S--,T--;
  vector<vector<int>> d(n,vector<int>(3,-1));
  d[S][0] = 0;
  queue<P> que;
  que.push(make_pair(S,0));
  while(!que.empty()){
    P ov = que.front();que.pop();
    for(auto nv : v[ov.first]){
      if(d[nv][(ov.second+1)%3] != -1)continue;
      d[nv][(ov.second+1)%3] = d[ov.first][ov.second] + 1;
      que.push(make_pair(nv,(ov.second+1)%3));
    }
  }
  cout << (d[T][0] != -1 ? d[T][0]/3 : -1) << endl;



  return 0;
}