#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int dig[10][10];int n;
void ass(int x)
{
	string s=to_string(x);
	int l=s.length();
	dig[s[0]-'0'][s[l-1]-'0']++;
}
int32_t main()
{
	n=in();
	for(int i=1;i<=n;i++)
	{
		ass(i);
	}
	
	int ans=0;
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		ans+=(dig[i][j]*dig[j][i]);
	}
	cout<<ans;
	
}