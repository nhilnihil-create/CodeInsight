#include <stdio.h>

const long long mod = 1000000007;

long long fpow(long long a, long long p)
{
	long long r = 1;
  while (p){
if (p & 1) r = r * a % mod;
    a = a * a % mod;
    p /= 2;
  }
  return r;
}

int n,k;
long long phi[100100];

int main()
{
  scanf ("%d %d",&n,&k);
 for (int i=1;i<100100;i++){
    phi[i] = fpow(i,n);
   int s = 2;
   while (s <= i){
	int e = i / (i / s) + 1;
     phi[i] = (phi[i] + mod - (e - s) * phi[i/s] % mod)%  mod;
     s = e;
   }
 }
  long long ans = 0;
  for (int i=1;i<=k;i++) ans = (ans + i * phi[k/i]) % mod;
  printf ("%lld\n",ans);
return 0;
}
