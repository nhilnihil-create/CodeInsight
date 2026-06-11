#include <cstdio>
#include <utility>
#include <vector>
#define rep(i,a) for(int i=0;i<(a);++i)

int n;
std::vector<std::vector<int> > G;
std::vector<bool> used;
std::vector<std::pair<int, int> > res;
int tim = 1;

void dfs( int v )
{
  used[v] = true;
  res[v].first = tim++;

  for( int u : G[v] ) if( !used[u] )
    dfs( u );

  res[v].second = tim++;

  return;
}

int main()
{
  scanf( "%d", &n );
  G.resize( n );
  used.resize( n );
  res.resize( n );

  rep( i, n )
  {
    int u, k;
    scanf( "%d%d", &u, &k );

    rep( j, k )
    {
      int v;
      scanf( "%d", &v );
      G[i].push_back( v-1 );
    }
  }

  rep( i, n ) if( !used[i] )
    dfs( i );

  rep( i, n )
    printf( "%d %d %d\n", i+1, res[i].first, res[i].second );

  return 0;
}