#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 10000;
map<P,bool> unused;
void dfs(P ball,P v){
  unused[ball] = false;

  P to1(ball.first+v.first,ball.second+v.second);
  P to2(ball.first-v.first,ball.second-v.second);

  if(unused[to1] == true){
    dfs(to1,v);
  }

  if(unused[to2] == true){
    dfs(to2,v);
  }

  return;
} 
    

int main(){
  int n;
  cin >> n;

  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  vector<P> vec;
  vector<P> ball(n);

  for(int i = 0;i < n;i++){
    int x,y;
    cin >> x >> y;
    ball[i] = P(x,y);
  } 

  for(int i = 0;i < n - 1;i++){
    for(int j = i + 1;j < n;j++){
      int x1 = ball[i].first;
      int y1 = ball[i].second;
      int x2 = ball[j].first;
      int y2 = ball[j].second;
      vec.push_back(P(x1-x2,y1-y2));
    }
  }

  int ans = INF;
  for(P v:vec){
    int now = 0;
    for(int i = 0;i < n;i++)unused[ball[i]] = true;
    for(int i = 0;i < n;i++){
      if(unused[ball[i]] == true){
	dfs(ball[i],v);
	now++;
      }
    }
    ans = min(ans,now);    
  }        

  cout << ans << endl;
}
