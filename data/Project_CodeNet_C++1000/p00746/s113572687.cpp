#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define pf push_front 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i,n) for(int i=0;i<(n);i++)
#define All(v) v.begin(),v.end()
typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;

int N;
vector<Pii> graph[201];
bool used[201];
int way[201][201];
int max_y, min_y, max_x, min_x;

void dfs( int n, int x, int y ) {
  //cout << n << " " << x << " " << y << endl; 
  max_y = max( max_y, y );
  max_x = max( max_x, x );
  min_y = min( min_y, y );
  min_x = min( min_x, x );
  
  if( !used[n] ) {
    used[n] = true;
    for(int i=0; i<graph[n].size(); i++) {
      //cout << 'a' << endl;
      Pii p = graph[n][i];
      int next = p.fr, way = p.sc;

      if( way == 0 ) {
	dfs( next, x-1, y );
      }
      if( way == 1 ) {
	dfs( next, x, y-1 );
      }
      if( way == 2 ) {
	dfs( next, x+1, y );
      }
      if( way == 3 ) {
	dfs( next, x, y+1 );
      }
    }
  }
  
}

main()
{
  while( cin >> N, N ) {
    fill_n(used, 201, false);
    Rep(i, 201) graph[i].clear();
    
    Rep(i, N-1) {
      int n, d;
      cin >> n >> d;
      graph[i+1].pb( Pii(n, d) );
      graph[n].pb( Pii(i+1, (d+2)%4) );
    }

    max_y = max_x = min_y = min_x = 0;
    dfs( 0, 0, 0 );

    cout << max_x - min_x + 1 << " " << max_y - min_y + 1 << endl;							   
  }
}