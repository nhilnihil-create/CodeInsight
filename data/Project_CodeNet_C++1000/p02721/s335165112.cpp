#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;
//typedef __int64 LL;
typedef pair<int,int> P;
const int INF=1000000000;
const int MOD_2=998244353;

int l[200010],r[200010];

int main()
{
	int n,k,c;
	int count=0;
	string s;
	cin>>n>>k>>c>>s;
	
	fill(l,l+k,INF);
	fill(r,r+k,INF);
	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='x')continue;
		else
		{
			l[count]=i;
			count++;
			i+=c;
		}
		if(count>=k)break;
	}
	
	count=k-1;
	
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='x')continue;
		else
		{
			r[count]=i;
			count--;
			i-=c;
		}
		if(count<0)break;
	}
	
	if(l[k-1]!=INF)
	{
		for(int i=0;i<k;i++)
		{
			if(l[i]==r[i])cout<<l[i]+1<<"\n";
		}
	}
	return 0;
}
	