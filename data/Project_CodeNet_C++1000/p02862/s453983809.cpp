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
#include <iomanip>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

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

LL kaijou(LL a)
{
	LL ans=1;
	for(LL i=1;i<=a;i++)
	{
		ans=(ans*i)%MOD;
	}			
	return ans;
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

int main(){
	LL x,y;cin>>x>>y;
	if((x+y)%3!=0 || 2*x<y || 2*y<x)
	{
		cout<<0<<"\n";
		return 0;
	}
	
	LL a=(2*y-x)/3,b=(2*x-y)/3;
	
	
	cout<<combi(a+b,b)<<"\n";
	return 0;
}