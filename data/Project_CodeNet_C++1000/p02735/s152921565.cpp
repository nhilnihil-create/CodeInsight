#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int H, W;
  cin>>H>>W;
  vector<string> S(H);
  for(int i=0;i<H;++i) cin>>S[i];
  priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int> >, greater<tuple<int, int, int, int> > > que; // cost, black, zahyo
  if(S[0][0]=='.') que.push(mt(0, 0, 0, 0));
  else que.push(mt(1, 1, 0, 0));
  tuple<int, int, int, int> state;
  int cost, black, x, y;
  int ans[H][W];
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      ans[i][j] = inf;
    }
  }
  while(!que.empty()) {
    state = que.top();que.pop();
    cost = get<0>(state);
    black = get<1>(state);
    x = get<2>(state);
    y = get<3>(state);
    if(ans[x][y]<=cost) continue;
    ans[x][y] = cost;
    if(black) {
      if(x<H-1) {
        if(S[x+1][y]=='#') {
          que.push(mt(cost, black, x+1, y));
        }
        else {
          que.push(mt(cost, black-1, x+1, y));
        }
      }
      if(y<W-1) {
        if(S[x][y+1]=='#') {
          que.push(mt(cost, black, x, y+1));
        }
        else {
          que.push(mt(cost, black-1, x, y+1));
        }
      }
    }
    else {
      if(x<H-1) {
        if(S[x+1][y]=='#') {
          que.push(mt(cost+1, black+1, x+1, y));
        }
        else {
          que.push(mt(cost, black, x+1, y));
        }
      }
      if(y<W-1) {
        if(S[x][y+1]=='#') {
          que.push(mt(cost+1, black+1, x, y+1));
        }
        else {
          que.push(mt(cost, black, x, y+1));
        }
      }
    }
  }
  /**
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  **/
  cout<<ans[H-1][W-1]<<endl;
}

