#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef pair<int,int> P;

const int MOD=1000000007;

LL beki(LL a,LL b)
{
	if(b==0)return 1;
	LL x=beki(a,b/2);
	if(b%2==0)return (x*x)%MOD;
	else return (((a*x)%MOD)*x)%MOD;
}

LL inv(LL a)
{
	return beki(a,MOD-2);
}



LL combi(LL a,LL b)
{
	LL ret=1;
	for(LL i=1;i<=b;i++)
	{
		ret=(((ret*(a+1-i))%MOD)*inv(i))%MOD;
	}
	return ret;
}

int main()
{
	LL n;
	LL a,b;
	LL ans=0;
	cin>>n>>a>>b;
	
	ans=(beki(2,n)-1-combi(n,a)-combi(n,b)+MOD*2)%MOD;
	cout<<ans<<"\n";
	
	return 0;
}