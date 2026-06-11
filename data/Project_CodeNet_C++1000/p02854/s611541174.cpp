#include <bits/stdc++.h>

using namespace std;

int n;
int arr[200005];

int main()
{
	cin >> n;
	long long a=0,b=0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		a+=arr[i];
	}
	long long ans=a;
	for(int i=0;i<n;i++)
	{
		a-=arr[i]; b+=arr[i];
		ans=min(ans,llabs(a-b));
	}
	cout << ans << endl;
}