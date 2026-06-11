#include <cstdio>
#include <algorithm>
#define rep(i,n) for(int i=0; i<(n); ++i)
main()
{
   int N, a[2000001];
   scanf("%d", &N);
   rep(i, N)scanf("%d", a+i);
   std::sort(a, a+N);
   rep(i, N)printf("%d%c", a[i], i+1 < N ? ' ' : '\n' );
}

