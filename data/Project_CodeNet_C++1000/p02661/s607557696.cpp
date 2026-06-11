#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n; cin >> n;
   int a[n+1], b[n+1];
   for(int i =0; i < n; i++)
   {
      cin >> a[i]  >> b[i];
   }
   sort(a, a+n);
   sort(b, b+n);
   int x, y;
   if(n&1)
   {
      x = a[n/2];
      y = b[n/2];
   }
   else
   {
      x = (a[n/2 - 1] + a[n/2]);
      y = (b[n/2 - 1] + b[n/2]);
   }
   cout << y - x + 1;

}
