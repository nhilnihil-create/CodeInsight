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
	
	ll int n;
	
	while(cin>>n)
	{
		
		string ans="";
		
		while(n)
		{
			n--;
			
			int now=n%26;
			
			ans+=('a'+now);
			
			n/=26;
		}
		
		reverse(ans.begin(),ans.end());
		
		cout<<ans<<endl;
	}
	
	return 0;
}