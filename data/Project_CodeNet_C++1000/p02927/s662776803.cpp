#include <bits/stdc++.h>
using namespace std;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define watch(x) cout<<"->"<<#x<<": "<<x<<endl;
// #define int long long
const int INF = 1000000000;
const int MOD = 1000000007;
const double PI = 2*acos(0.0);
signed main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m,d;
	cin>>m>>d;
	int res = 0;
	for(int k=1;k<=m;k++)
	{
		int curr = 0;
		for(int i=22;i<=d&&i<=99;i++)
		{
			int x = i%10, y = i/10;
			if(x>=2&&y>=2&&x*y==k)
				++curr;
		}
		res+=curr; 
	}
	return cout<<res<<endl,0;	
}