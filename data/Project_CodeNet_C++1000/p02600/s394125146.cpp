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
	
	int x;
	
	while(cin>>x)
	{
		if(x<=599)
			cout<<8<<endl;
		else if(x<=799)
			cout<<7<<endl;
		else if(x<=999)
			cout<<6<<endl;
		else if(x<=1199)
			cout<<5<<endl;
		else if(x<=1399)
			cout<<4<<endl;
		else if(x<=1599)
			cout<<3<<endl;
		else if(x<=1799)
			cout<<2<<endl;
		else if(x<=1999)
			cout<<1<<endl;	
		
	}
	
	return 0;
}