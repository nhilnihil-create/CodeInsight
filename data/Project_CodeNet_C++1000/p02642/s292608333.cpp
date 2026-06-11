#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<list>
#include<stack>
//#include<unordered_map>
using namespace std;
#define ll long long
#define dd cout<<endl
const long long int inf = 1e18+7;
const int mod = 998244353;

using namespace std;

inline ll int max(ll int a,ll int b) { return a>b?a:b; }
inline ll int min(ll int a,ll int b) { return a<b?a:b; }

const int maxn=1e6+10;

bool bk[maxn];

int num[maxn];

int main()
{
//	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n;
	
	scanf("%d",&n);
	
	int maxx=-1;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		
		if(num[i]>maxx)
			maxx=num[i];
	}
	
	sort(num,num+n);
	
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		if(bk[num[i]]==false)
		{
			if(num[i]!=num[i+1])
				cnt++;
			
			int now=num[i];
			
			while(now<=maxx)
			{
				bk[now]=true;
				now+=num[i];
			}
			
		}
	}
	
	printf("%d\n",cnt);
	
	return 0;
}