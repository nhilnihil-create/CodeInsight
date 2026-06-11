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
#include <cmath>
#include <functional>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;


const int MOD=1000000007;
int INF=100100100;

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

LL seki(LL a,LL b)
{
	return (a*b)%MOD;

}

LL wa(LL a,LL b)
{
	return (a+b)%MOD;
}
int main(){
        map<LL,LL> ma;
	LL n;cin>>n;
        for(LL i=0;i<n;i++)
	{
		LL a;cin>>a;
		for(LL j=0;j<62;j++)
		{
			if((a>>j)%2==1)ma[j]++;
		}
	}
	LL ans=0;
	for(LL i=0;i<62;i++)
	{
		
//		cout<<ans<<endl;
		ans=wa(ans,seki(seki(ma[i],n-ma[i]),beki(2,i)));
	}
//	cout<<ans<<endl;
	//ans=(ans*inv(2))%MOD;
	cout<<ans<<endl;
	return 0;
}