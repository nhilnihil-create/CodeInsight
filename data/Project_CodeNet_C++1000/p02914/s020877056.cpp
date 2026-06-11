#include <stdio.h>

int n; long long a[100100], x;

int main()
{
  scanf ("%d",&n);
  for (int i=0;i<n;i++){
	scanf ("%lld",&a[i]);
    x ^= a[i];
  }
  
  long long basis[64] = {0,};
  for (int k=0;k<n;k++){
    long long v = (a[k] | x) ^ x;
    for (int i=62;i>=0;i--) if (v & (1ll << i)){
      if (!basis[i]){basis[i] = v; break;}
      else v ^= basis[i];
    }
  }
  
  long long ans = 0;
  for (int i=62;i>=0;i--){
	if ((ans & (1ll << i)) == 0) ans ^= basis[i];
  }
  ans *= 2;
  ans += x;
  printf ("%lld\n",ans);
  

return 0;
}
