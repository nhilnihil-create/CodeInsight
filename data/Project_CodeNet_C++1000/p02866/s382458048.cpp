#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
 
#define SIZE 100005
#define AM 998244353;
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
 
using namespace std;
 
ll rui(ll a, ll b)
{
	ll c=1;
	while(b>0)
	{
		c=(c*a)%AM;
		b--;
	}
	return c;
}
 
int main()
{	
	ll N;
	scanf("%lld", &N);
	ll D[N];
	ll count[N];
	for(ll i=0;i<N;i++){
		scanf("%lld", &D[i]);
		count[i]=0;
	}
	
 
	for(ll i=0;i<N;i++){
		count[D[i]]++;
	}
	
	ll answer=1; 
 
	
	
	
	
	ll yos=1;
	if((count[0]!=1)||(D[0]!=0)){answer=0;}
	for(ll i=1;i<N;i++){
		if((count[i]!=0)&&(yos==1))
		{
		answer=(answer*rui(count[i-1],count[i]))%AM;
		}
		else
		{
			if((count[i]!=0)&&(yos==0))
			{
				answer=0;
			}
			yos=0;
		}
			
	}
	
	printf("%lld", answer);
}