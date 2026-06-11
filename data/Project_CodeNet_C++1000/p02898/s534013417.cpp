#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll mod=1000000007;
int main()
{
	fast;
	int n;cin>>n;
	int k;cin>>k;
	int c=0;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		if(x>=k)c++;
	}
	cout<<c;
}