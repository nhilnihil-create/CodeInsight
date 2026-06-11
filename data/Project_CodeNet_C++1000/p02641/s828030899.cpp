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

const int maxn=205;

bool bk[maxn];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int x,n;
	
	cin>>x>>n;
	
	for(int i=0,y;i<n;i++)
	{
		cin>>y;
		bk[y]=true;
	}
	
	for(int i=0,now;;i++)
	{
		now=x-i;
		if(!bk[now]) {
			return cout<<now<<endl,0;
		}
		
		now=x+i;
		if(!bk[now]) {
			return cout<<now<<endl,0;
		}
	}
	
}