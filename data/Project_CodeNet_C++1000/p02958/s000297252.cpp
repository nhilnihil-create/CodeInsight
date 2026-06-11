#include <stdio.h>
#include <algorithm>
using namespace std;

int n,p[55];
int main()
{
scanf ("%d",&n);
  for (int i=0;i<n;i++) scanf ("%d",&p[i]);
  
  if (is_sorted(p,p+n)){
puts("YES");
    return 0;
  }
  for (int i=0;i<n;i++) for (int j=i+1;j<n;j++){
swap(p[i],p[j]);
  if (is_sorted(p,p+n)){
puts("YES");
    return 0;
  }
swap(p[i],p[j]);
  }
  puts("NO");
  return 0;
}