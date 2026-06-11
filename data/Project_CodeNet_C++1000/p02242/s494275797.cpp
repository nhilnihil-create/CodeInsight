#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#define F first
#define S second
using namespace std;
typedef pair<int,int>p;

vector<p>g[103];
int d[103];
main()
{
  int n;
  int u, k, v, c;
  
  scanf("%d", &n);
  for (int i = 0; i < n ; ++i) {
    scanf("%d %d", &u, &k);
    for(int j = 0; j < k ; ++j) {
      scanf("%d %d", &c, &v);
      g[u].push_back(p(c,v));
    }
    d[i] = 1 << 21;
  }
  
  priority_queue< p, vector<p>, greater<p> >p_que;
  p_que.push(p(0,0));
  d[0] = 0;
  while ( !p_que.empty() ) {
    p now = p_que.top(); p_que.pop();
    int pos = now.F;
    int cost = now.S;
    for ( int i = 0; i < g[pos].size() ; ++i) {
      int ncost = cost + g[pos][i].S;
      if ( ncost < d[g[pos][i].F] ) {
	d[g[pos][i].F] = ncost;
	p_que.push(p(g[pos][i].F,ncost));
      }
    }
  }

  for ( int i = 0; i < n ; ++i) {
    printf("%d %d\n", i, d[i]);
  }

  return (0);
}

