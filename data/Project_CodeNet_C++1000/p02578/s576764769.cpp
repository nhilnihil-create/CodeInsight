#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
int main()
{
ll n,i,c=0;
cin>>n;
ll a[n];
for(int j=0;j<n;j++)
cin>>a[j];
for(i=0;i<n-1;i++)
{
	while(a[i]>a[i+1])
	{
		a[i+1]++;
		c++;
	}
}
cout<<c<<endl;
}