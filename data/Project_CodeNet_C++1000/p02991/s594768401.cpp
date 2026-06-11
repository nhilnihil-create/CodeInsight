#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
typedef pair<int,int> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int dist[1101010][3];
signed main(){
  int n,m;
  cin >> n >> m;
  vvint to(n);
  rep(i,0,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    to[a].push_back(b);
  }
  rep(i,0,n){
    rep(j,0,3){
      dist[i][j] = INF;
    }
  }
  int sv,tv;
  cin >> sv >> tv;
  sv--;tv--;
  dist[sv][0] = 0;
  queue<P> que;
  que.push(P(sv,0));
  while(!que.empty()){
    P key = que.front();
    int val = key.first;
    int num = key.second;
    que.pop();
    for(int p:to[val]){
      int nnum = (num+1)%3;
      if(dist[p][nnum] == INF){
        dist[p][nnum] = dist[val][num]+1;
        que.push(P(p,nnum));
      }
    }
  }
  if(dist[tv][0] == INF) cout << -1 << endl;
  else cout << dist[tv][0]/3 << endl;
}