#include <bits/stdc++.h>
using namespace std;
int n,i,j,b[1000100],r;
char a[1000100];
bool ok=false;
int main() {
  scanf("%d",&n);
  scanf("%s",a);
  for (i=0; i<n; i++) {
    a[i]=a[i]-'1';
    if (a[i]==1) ok=true;
    b[i+1]=b[i];
    for (j=i+1; j%2==0; j/=2) b[i+1]++;
  }
  if (!ok) for (i=0; i<n; i++) a[i]/=2;
  for (i=0; i<n; i++) if (a[i]==1 && b[n-1]==b[i]+b[n-1-i]) r^=1;
  if (!ok) r*=2;
  printf("%d\n",r);
  return 0;
}
