#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=2e5+10;
int n;
int a[maxn],b[maxn];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[i]=x+y,b[i]=x-y;
	}
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	cout<<max(a[n]-a[1],b[n]-b[1])<<endl;
	return 0;
}

