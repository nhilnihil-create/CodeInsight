#include<bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
typedef long long ll;
long long int wy(long long int a,long long int b)
 {
 	long long int res=1;
 	while (b)
 	{
 		if (b&1) res=res*a%mod;
 		a=a*a%mod;
 		b>>=1;
	 }
	 return res;
  } 
  int main()
  {
  	long long int n,m;
  	scanf("%lld",&n);
  	if (n==2) {
  		printf("%lld\n",n); return 0;
	  }
	  else if (n<2) {
	  	printf("%lld\n",0); return 0;
	  }
  	m=(wy(10,n)-wy(9,n)-wy(9,n)+wy(8,n))%mod; 	
  	if (m<0) m+=mod;
  	printf("%lld\n",m);
  	return 0;
  }