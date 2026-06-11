#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz];

int main()
{
   int n;
   ll tot = 0;
   scanf("%d", &n);
   for(int i=0; i<=n; i++)
      scanf("%d", &a[i]), tot += a[i];

   ll ans = 0, x = 1;
   for(int i=0; i<=n; i++) {
      if(x < a[i]) {
         puts("-1");
         exit(0);
      }
      ans += x;
      x -= a[i];
      tot -= a[i];
      x = min(x << 1, tot);
   }

   if(!n && !a[0]) ans = 0;
   printf("%lld\n", ans);
}
