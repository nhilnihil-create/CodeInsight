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

//const int maxn=

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int x,y;
	
	cin>>x>>y;
	
	for(int i=0,j;i<=x;i++)
	{
		j=x-i;
		
		if(i*4+j*2==y)
		{
			return cout<<"Yes"<<endl,0;
		}
	}
	
	return cout<<"No"<<endl,0;
	
}