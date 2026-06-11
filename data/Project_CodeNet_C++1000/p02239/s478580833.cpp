#include<iostream>
#include<queue>
#include<utility>
#define F first
#define S second
using namespace std;
typedef pair< int, int >p;//first = node , second = time

bool g[101][101];
int t[101];

main()
{
  int n, u, k, v;
  queue<p>que;

  cin >> n;

  for ( int i = 0; i < n ; ++i) {
    t[i] = -1;
    for(int j = 0; j < n ; ++j) {
      g[i][j] = false;
    }
  }
  
  for (int i = 0; i < n ; ++i) {
    cin >> u >> k; --u;
    
    for (int j = 0; j < k ; ++j) {
      cin >> v; --v;
      g[u][v] = true;
    }
  }

  que.push(p(0,0));
  t[0] = 0;
  while ( !que.empty() ) {
    p now = que.front(); que.pop();
    
    int pos = now.F;
    int time = now.S;
    
    for ( int i = 0; i < n ; ++i) {
      if ( g[pos][i] && t[i] == -1 ) {
	t[i] = time + 1;
	que.push(p(i,time+1));
      }
    }
  }

  for ( int i = 0; i < n ; ++i) {
    cout << i + 1 << " " << t[i] << endl;
  }
  
  return (0);
}

