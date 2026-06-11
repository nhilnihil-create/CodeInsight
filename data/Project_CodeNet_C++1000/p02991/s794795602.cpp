#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int check[110000][3];
vector<vin> g;

void bfs(int now,int r,int dis){
  queue<P> que;
  que.push(mp(now,r));
  check[now][r]=dis;
  while(!que.empty()){
    int w=que.front().first;
    int z=que.front().second;
    int dist=check[w][z];
    que.pop();
    if(z==0)dist++;
    for(auto v:g[w]){
     if(check[v][(z+1)%3]!=-1)continue;
      
      check[v][(z+1)%3]=dist;
      que.push(mp(v,(z+1)%3));
    }
  }
  
  
  return ;
}

int main(){cout<<fixed<<setprecision(20);
		   //3で割ったあまりで判定する？
           int n,m;
           cin>>n>>m;
           g.resize(n);
           rep(i,0,m){
            int a,b;
             cin>>a>>b;
             a--;b--;
             g[a].pb(b);
           }
           rep(i,0,n){
            rep(j,0,3)check[i][j]=-1; 
           }
           int s,t;
           cin>>s>>t;
           s--;t--;
           bfs(s,0,0);
           cout<<check[t][0]<<endl;
           //間に合う？
}

