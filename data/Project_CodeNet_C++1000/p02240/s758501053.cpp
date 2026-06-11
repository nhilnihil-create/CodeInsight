#include <cstdio>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(n); ++i)

int parent[100005];

int find(int x){
   if( parent[x] == x )return x;
   return parent[x] = find( parent[x] );
}

void unite(int x, int y)
{
   x = find(x);
   y = find(y);

   if(x == y)return;
   parent[x] = y;
}

int main()
{
   int N, M;
   int x, y, tmp;
   scanf("%d%d", &N, &M);
   std::iota(parent, parent + N, 0);

   rep(i, M){
      scanf("%d%d", &x, &y);
      unite(x, y);
   }

   int Q;
   scanf("%d", &Q);
   while(Q--){
      scanf("%d%d", &x, &y);
      puts( find(x) == find(y) ? "yes" : "no" );
   }
}

