#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#define ll long long
#define lson (rt<< 1)
#define rson (rt<< 1 | 1)
#define gmid ((l+r)>> 1 )
using namespace std;

const int maxn=20000050; 

char s[maxn];
int cnt[maxn],n,p; 

int main()
{
	cin>>n>>p;
	ll ans=0;
	scanf("%s",s);
	if(p==2||p==5)
	  {
	  	  for(int i=0;i<n;++i)
	  	    if((s[i]-'0')%p==0)
	  	      ans+=i+1;
	  }
	else 
	  {
		  ll t=1,res=0;
		  for(int i=n-1;i>=0;--i)
		    {
		    	cnt[res]++;
		    	res=(res+(s[i]-'0')*t)%p;
		    	t=t*10%p;
		    	ans+=cnt[res];
		    }
	  }  
	printf("%lld\n",ans);
	return 0;  
}
