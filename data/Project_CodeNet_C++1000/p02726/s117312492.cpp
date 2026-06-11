#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
const int INF = 0x7fffffff;
using lll = long long;
using ull = unsigned long long;
using namespace std;
using Graph = vector<vector<int>>;
int dist[2001][2001];

int main(){
  lll ii,jj,kk;
  vector<int> ret;

  int n,x,y;
  
  cin >> n >> x >> y;

  Graph g(n);

  for(ii=0;ii<n-1;ii++){

    g[ii].push_back(ii+1);
    g[ii+1].push_back(ii);
    
  }

  g[x-1].push_back(y-1);
  g[y-1].push_back(x-1);
  
  vector<int> todo;
  vector<bool> seen(n);


  int v;
  //cout << "start" << endl;

  memset(dist,0,sizeof(dist));

  for(ii=0;ii<n;ii++){
    seen.assign(n,false);
    seen[ii] = true;
    todo.push_back(ii);
    dist[ii][ii] = 0;

    while(!todo.empty()){
      v = todo[0];

      todo.erase(todo.begin());
      //cout << "v:" << v << endl;
      
      for(auto w : g[v]){
        if(seen[w] == true){continue;}

        seen[w] = true;
        todo.push_back(w);
        dist[ii][w] = dist[ii][v] + 1;
      }

    }
  }

  lll ans[2001];
  memset(ans,0,sizeof(ans));
  
  for(ii=0;ii<n;ii++){
    for(jj=ii+1;jj<n;jj++){
      //cout << dist[ii][jj] << " ";
      ans[dist[ii][jj]]++;
    }
    //cout << endl;
  }

  for(ii=1;ii<n;ii++){
    cout << ans[ii] << endl;
  }
  return 0;
}
