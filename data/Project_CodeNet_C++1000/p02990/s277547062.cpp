#include<iostream>
using namespace std;
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<set>
#include<cmath>
#define mod 1000000007
#define inf 1000000000000000
#define int long long int
int fact[10000];
int power(int a,int b)
{
	if(b==0)
	   return 1;
	else
	{
		int r=power(a,b/2);
		if(b%2==0)
		{
			return (r*r)%mod;
		}
		else
		{
			int x=(r*r)%mod;
			return (a*x)%mod;
		}
	}
}
void function2()
{
	fact[0]=1;
	int j;
	for(j=1;j<10000;j++)
	{
		fact[j]=(j*fact[j-1])%mod;
	}
}
int ncr(int n,int r)
{
	if(n<0||r<0||n<r)
	   return 0;
    int answer=1;
    answer=fact[n];
    answer*=power(fact[r],mod-2);
    answer=answer%mod;
    answer*=power(fact[n-r],mod-2);
    answer=answer%mod;
    return answer;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     function2();
     int n,k;
     cin>>n>>k;
     int i;
     for(i=1;i<=k;i++)
     {
		 int here=ncr(k-1,i-1);
		 here*=ncr(n-k+1,i);
		 here%=mod;
		 cout<<here<<endl;
	 }
}
