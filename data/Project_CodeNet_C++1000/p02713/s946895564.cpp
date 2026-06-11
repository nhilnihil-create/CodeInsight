#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using ll = long long;
ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}
int main(void) {
  int k;cin>>k;
  int ans=0;
  for (int i=1;i<=k;i++){
    for (int j=1;j<=k;j++){
      for (int l=1;l<=k;l++){
        ans+=gcd(i,gcd(j,l));
      }
    }
  }
  printf("%d\n",ans);
}