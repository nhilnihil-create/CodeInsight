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

const int maxn=2e5+100;

int num[maxn];

int pre[maxn];

int lst[maxn];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n;
	
	cin>>n;
		
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		pre[i]=pre[i-1]^num[i];
	}
	
	for(int i=n;i>=1;i--)
	{
		lst[i]=lst[i+1]^num[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<(pre[i-1]^lst[i+1])<<" ";
	}
	cout<<endl;
	
	return 0;
}