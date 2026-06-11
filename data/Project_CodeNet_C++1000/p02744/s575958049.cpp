#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll maxn=1e6+10;
char s[maxn];
ll n,ans;
void dfs(ll num)
{
	if(num==n)
	{
		for(int i=0;i<n;i++)
			cout<<s[i];
		cout<<endl;
		return;
	}
	for(int i=0;i<=ans;i++)
	{
		s[num]='a'+i;
		ll tmp=ans;
		if(i==ans) ans++;
		dfs(num+1);
		ans=tmp;
	}
}

int main()
{
	cin>>n;
	dfs(0);
	return 0;
}