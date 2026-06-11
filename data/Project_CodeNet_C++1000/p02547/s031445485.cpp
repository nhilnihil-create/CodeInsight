#include<bits/stdc++.h>
using namespace std;
#define pb  push_back
#define mod 1000000007
#define INF 1e18
typedef  long long ll;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int a[n],b[n],c=0,f=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i]>>b[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if(c>=0&&a[i]==b[i]){
			c++;
			if(c>=3)
				f=1;
		}
		else
			c=0;
	}
	if(f==1)
		cout<<"Yes";
	else
		cout<<"No";

	return 0;
}