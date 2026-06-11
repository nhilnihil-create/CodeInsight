#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,a[21],b[21],c[20],sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>b[i];
		sum+=b[i];
	}
	for(int i=0;i<n-1;i++)
	cin>>c[i];
	for(int i=0;i<n-1;i++)
	if(a[i]==a[i+1]-1)sum+=c[a[i]-1];
	cout<<sum;
    return 0;
}
