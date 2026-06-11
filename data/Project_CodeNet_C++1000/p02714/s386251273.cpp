#include <stdio.h>

int n; char s[4040];

int main()
  
{
scanf ("%d",&n);
  scanf ("%s",s);
  
  int r =0,g=0,b=0;
  for (int i=0;i<n;i++){
if (s[i] == 'R') r++;
if (s[i] == 'G') g++;
if (s[i] == 'B') b++;
  }
  
  long long ans = 1ll * r * g * b;
  
  for (int i=0;i<n;i++){

for (int d=1;0<=i-d&&i+d<n;d++){
if (s[i] != s[i-d] && s[i] != s[i+d] && s[i-d]!=s[i+d]) ans--;
}
  }
  printf ("%lld\n",ans);
  return 0;
}
