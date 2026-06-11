#include <bits/stdc++.h>
#define MOD 1000000007
using ll = long long;
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  char str[2*n];
  scanf("%s",&str);
  if((str[0] == 'W') || (str[2*n-1] == 'W')){
    printf("0\n");
    return 0;
  }
  
  int ar[2*n]; // 0:left 1:right
  ar[0] = 0;
  for(int i=1; i<2*n; i++){
	ar[i] = (str[i] == str[i-1] ? 1 - ar[i-1] : ar[i-1]);
  }
  
  ll ans = 1;
  int l = 0;
  int r = 0;
  for(int i=0; i<2*n; i++){
    if(ar[i] == 1){
      ans = (ans * (ll)(l - r) % MOD) % MOD;
      r++;
    }
    else
    {
      l++;
    }
  }
  if(l!=r) ans = 0;
  for(int i=1; i<=n; i++) ans = (ans * i) % MOD;   
  printf("%d\n",ans);
  return 0;
}
