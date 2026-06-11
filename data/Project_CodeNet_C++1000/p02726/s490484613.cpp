#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

static const int INF = (1<<21);
static const int N = 2010;
vector <int> ans(N);
int n, x, y;

void bfs(int s){
  //cout << "start BFS" << s << endl;
  vector<int> d(n);
  REP(i,n) d[i] = INF;

  queue<int> q;
  q.push(s);
  int now;
  now = s;
  d[now] = 0;
  while( !q.empty()){
    now = q.front(); q.pop();
    //if(d[now] != INF) continue; //既に訪れていたら飛ばす
    if(now == x) {
      //cout << "1" << endl;
      if(d[y] == INF){
        d[y] = d[now] + 1;
        q.push(y);
      }
    }

    if(now == y){
      //cout << "2" << endl;
      if(d[x] == INF){
        d[x] = d[now] + 1;
        q.push(x);
      }
    }
    if(now - 1 >= 0){
      //cout << "3" << endl;
      if(d[now-1] == INF){
        d[now - 1] = d[now] + 1;
        q.push(now-1);
      }
    }
    if(now + 1 < n){
      //cout << "4" << endl;
     if (d[now+1] == INF){
       d[now + 1] = d[now] + 1;
       q.push(now+1);
     }
    }
  }
  REP(i,n) ans[d[i]]++; //始点からの距離ごとに集計
}

int main(){
  cin >> n >> x >> y;
  --x; --y;

  REP(i,n) ans[i] = 0;

  REP(i,n){
    bfs(i);
  }
//各頂点ごとに双方向から調べているため，半分に．
  REP(i,n) ans[i] /= 2;

//OUTPUT
//cout << " ans " << endl;
  REP2(i,1,n){
    cout << ans[i] << endl;
  }

  return 0;
}
