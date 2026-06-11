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
LL n,k;
LL a[200020],f[200020];
const int MOD=1000000007;

bool hantei(LL x)
{
	LL sum=0;
	for(LL i=0;i<n;i++)
	{
		sum+=max((LL)0,a[i]-x/f[i]);	
	}
	return (sum<=k);
} 
int main(){
	LL ans=0;
	cin>>n>>k;
	for(LL i=0;i<n;i++)cin>>a[i];
	for(LL i=0;i<n;i++)cin>>f[i];
	sort(a,a+n);
	sort(f,f+n,greater<LL>());
	
	LL l=0,r=100000000000000;
	
	while(r-l>=1)
	{
		LL mid=(l+r)/2;
		bool flag=hantei(mid);
		if(flag)r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
	return 0;
}