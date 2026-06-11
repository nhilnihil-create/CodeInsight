#include <bits/stdc++.h>
using namespace std;
#define md 1000006
int p[md];
int main() {
  int n,x,gc=0;
  cin>>n;
  while(n--)
  {
	  cin>>x;
	  gc=__gcd(gc,x);
	  if(x%2==0) p[2]++;
	  while(x%2==0) x/=2;
	  for(int i=3;i*i<=x;i+=2)
	  {
		  if(x%i==0) p[i]++;
	  	  while(x%i==0) x/=i;
	  }
	  if(x>1) p[x]++;
  }
  bool f=0;
  for(int i=1;i<md;i++) if(p[i]>1) {
	  f=1;
	  break;
  }
  if(f==0) puts("pairwise coprime");
  else if(gc==1) puts("setwise coprime");
  else puts("not coprime");
}