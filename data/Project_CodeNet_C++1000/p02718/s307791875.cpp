#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define rep(i,n) for(int i=0;i<n;i++) 
#define all(v) v.begin(),v.end()
#define F first
#define S second

void solve()
{
	int n;
	double m;
	cin>>n>>m;
	int arr[n];
	ll sum=0;
	rep(i,n)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	ll val=ceil(sum/(4*m));
	ll count=0;
	rep(i,n)
	{
		if(arr[i]<val)
		{
			count++;
		}
	}
	if(n-count>=m)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}

	
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
	int t;
	t=1;
	while(t--)
	{
		solve();
	}
}