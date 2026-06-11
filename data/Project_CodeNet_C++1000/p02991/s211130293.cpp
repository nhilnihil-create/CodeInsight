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
    int N,M;
    cin>>N>>M;
    vector<vector<int>> g(N);
    for(int i = 0; i < M; i++){
        int x,y;
        cin>>x>>y;
        g[x-1].push_back(y-1);
    }
    int S,T;
    cin>>S>>T;
    S--;
    T--;
    queue<int> bfs;
    vector<int> d(N,-1);
    d[S]=0;
    bfs.push(S);
  	bool over = false;
    while(!bfs.empty()&&!over){
        int t = bfs.front();
        bfs.pop();
        for(auto x:g[t]){
          for(auto y:g[x]){
            for(auto z:g[y]){
              if(d[z]!=-1) continue;
              d[z]=d[t]+1;
              bfs.push(z);
              if(z==T) over = true;
            }
          }
        }
    }
    cout<<d[T]<<endl;
}