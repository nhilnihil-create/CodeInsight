#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll m=1000000007;

int main()
{
	fast;
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int XOR=a[0];
	vector<int>v;
	for(int i=1;i<n;i++)
	{
		XOR=XOR^a[i];
	}
	for(int i=0;i<n;i++)
	{
		v.push_back(a[i]^XOR);
	}
	for(auto i:v)
		cout<<i<<" ";
}