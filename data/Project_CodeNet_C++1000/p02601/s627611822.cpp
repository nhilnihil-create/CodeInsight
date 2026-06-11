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

inline void cal(int a,int b,int c,int k)
{
	
	if(a<b && b<c)
	{
		cout<<"Yes"<<endl;
		return ;
	}
	
	while(b<=a)
	{
		if(k)
		{
			b<<=1;
			k--;
		}
		else
		{
			cout<<"No"<<endl;
			return ;
		}
	}
	
	while(c<=b)
	{
		if(k)
		{
			c<<=1;
			k--;
		}
		else
		{
			cout<<"No"<<endl;
			return ;
		}
	}
	
	cout<<"Yes"<<endl;
	return ;
	
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int a,b,c,k;
	
	while(cin>>a>>b>>c>>k)
	{
		cal(a,b,c,k);
	}
	
	return 0;
}