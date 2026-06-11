#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N,M,Q;
  cin>>N>>M>>Q;
  vector<vector<int>> v(Q,vector<int>(4));
  for(int i = 0; i < Q; i++) cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3];
  queue<vector<int>> q;
  for(int i = 1; i <= M; i++){
    vector<int> p = {i};
    q.push(p);
  }
  while((int)q.front().size()!=N){
    vector<int> p = q.front();
    q.pop();
    int s = *(p.end()-1);
    for(int i = s;i<=M;i++){
      vector<int> t = p;
      t.push_back(i);
      q.push(t);
    }
  }
  int ans = 0;
  while(!q.empty()){
    vector<int> A = q.front();
    q.pop();
    int cnt = 0;
    for(auto x:v){
      if(A[x[1]-1]-A[x[0]-1]==x[2]) cnt+=x[3];
    }
    chmax(ans,cnt);
  }
  cout<<ans<<endl;
}