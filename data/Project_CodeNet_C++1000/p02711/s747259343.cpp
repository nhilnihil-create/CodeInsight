#include <stdio.h>

int main()
{
  bool g = 0;
  int n; scanf ("%d",&n);
  while (n){
if (n%10 == 7) g = 1;
    n /= 10;
  }
  puts(g?"Yes":"No");
return 0;
}