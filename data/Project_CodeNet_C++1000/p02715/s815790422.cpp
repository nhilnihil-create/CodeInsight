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
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;

const int MOD=1000000007;

LL beki(LL a,LL b)
{
	if(b==0)return 1;
	
	LL x=beki(a,b/2);
	if(b%2==0)return (x*x)%MOD;
	else return (((a*x)%MOD)*x)%MOD;
	
}

LL w[100010];
int main(){
	LL n,k;
	LL ans=0;
	cin>>n>>k;
	
	for(LL i=k;i>=1;i--)
	{
		LL num=beki(k/i,n);
		for(LL j=i*2;j<=k;j+=i)
		{
			num=(num-w[j]+MOD)%MOD;
		}
		w[i]=num;
		ans=(ans+i*num)%MOD;
		//cout<<num<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}