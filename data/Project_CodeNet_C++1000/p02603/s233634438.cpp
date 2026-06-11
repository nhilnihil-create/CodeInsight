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

const int maxn=105;

ll int num[maxn];

ll int book1[maxn];
ll int book2[maxn];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
    ll int n;
	
	while(cin>>n)
	{
		
		for(ll int i=1;i<=n;i++)
		{
			cin>>num[i];
		
		}
		
		ll int now=1000;
		
		ll int cnt=0;
		
		for(ll int i=1;i<n;i++)
		{
			if(num[i] < num[i+1])
			{
				ll int to=now/num[i];
				now+=(num[i+1]-num[i])*to;
			}
		}
		
		cout<<now<<endl;
	}
	
	return 0;
}