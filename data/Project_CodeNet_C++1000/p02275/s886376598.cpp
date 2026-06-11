#include <cstdio>
#include <algorithm>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define reps(i,f,n) for(int i=(f); i<=(n); ++i)
using namespace std;

main()
{
   int N, a[2000001], maxv = 0;
   scanf("%d", &N);

   rep(i, N)
      scanf("%d", a+i),
      maxv = max( maxv, a[i] );

   int cnt[maxv + 1] = {-1};
   int ret[N];

   rep(i, N) ++cnt[ a[i] ];
   reps(i, 1, maxv) cnt[i] += cnt[i-1];

   for(int i=N-1; i>=0; --i){
      int& p = cnt[ a[i] ];
      ret[p] = a[i];
      --p;
   }

   rep(i, N) printf("%d%c", ret[i], i+1 < N ? ' ' : '\n' );
}


