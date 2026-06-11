#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char a[maxn];
int n,k,ans,ok;
int main()
{
	cin >> n >> k >> (a+1);
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		if( a[i]==a[i-1] )	continue;
		else
			ans++;
	}
	cout << min(n-1,(n-ans)+k*2);
}