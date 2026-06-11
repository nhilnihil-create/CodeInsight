#include<bits/stdc++.h>
#define ll long long 
#define MM(arr,x) memset(arr,x,sizeof(arr))
#define INF 0x3f3f3f3f
#define Maxn 1e5+10;
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	string s;
	int n,cnt=0,ans=0;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R') cnt++;
	}
	for(int i=0;i<cnt;i++)
	{
		if(s[i]=='W') ans++;
	}
	cout<<ans;
	return 0;
} 