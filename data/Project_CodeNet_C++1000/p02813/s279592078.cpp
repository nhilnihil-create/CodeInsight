#include<iostream>
#include<algorithm> 
#include<cstring>
#define ios ios::sync_with_stdio(false)
#define mem(arr) memset(arr,0,sizeof(arr))
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;

int n,a[10],b[10],ans = 0; 

void solve(int a[],int b[])
{
	do
	{
		int flag = 1;
		for(int i = 0;i < n; i++)
		{
			if(a[i] != b[i])
			{
				flag = 0;
				ans++;
				break;
			}
		}
		if(flag) 
			break;
	}while(next_permutation(a,a+n));
}

int main()
{
	cin>>n;
	for(int i = 0;i < n; i++) 
		cin>>a[i];
	for(int i = 0;i < n; i++) 
		cin>>b[i];
	for(int i = 0;i < n; i++)
	{
		if(a[i] < b[i])
		{
			solve(a,b);
			break;
		}
		else if(a[i] > b[i])
		{
			solve(b,a);
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}