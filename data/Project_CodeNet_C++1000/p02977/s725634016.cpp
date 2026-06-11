#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d",&n);
  int d=1;
  while ((d<<1)<=n) d<<=1;
  if (d==n) {
  	puts("No");
  	return 0;
  }
  puts("Yes");
  for(int i=2;i<n;i+=2) {
  	printf("%d %d\n",1,i);
  	printf("%d %d\n",i,i+1);
  	printf("%d %d\n",1,i+1+n);
  	printf("%d %d\n",i+1+n,i+n);
  }
  if (!(n&1)) {
  	int u=d,v=(n^d);
  	printf("%d %d\n",u,n);
  	printf("%d %d\n",v+1+n,2*n);
  }
  printf("%d %d\n",3,n+1);
  return 0;
}