#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
ll n;
cin>>n;
ll count = 0;
ll a[n];
ll mi = INT_MAX;
for(int i = 0;i<n;i++)
{
	cin>>a[i];
	mi = min(mi,a[i]);
	if(mi==a[i]) count++;
}
cout<<count<<"\n";
}
