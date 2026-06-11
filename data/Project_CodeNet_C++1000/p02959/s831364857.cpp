#include <stdio.h>
#include <algorithm>
using namespace std;

int n,a[100100],b[100100];
int main()
{
  scanf ("%d",&n);
  for (int i=0;i<=n;i++) scanf ("%d",&a[i]);
  for (int i=0;i<n;i++) scanf ("%d",&b[i]);
  long long ans = 0;
  for (int i=0;i<n;i++){
    int v =  min(a[i],b[i]);
ans += v;
   	a[i] -= v;
    b[i] -= v;
    int w =  min(a[i+1],b[i]);
    ans += w;
    a[i+1]-=w;
    b[i] -= w;
  }
  printf ("%lld\n",ans);
return 0;
}