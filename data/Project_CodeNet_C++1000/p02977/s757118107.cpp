#include<bits/stdc++.h>
using namespace std;
int n,s=1;
int main()
{
	cin>>n;
	while(s*2<=n)
		s*=2;
	if(s==n)
	{
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<'\n'<<1+n<<' '<<3<<'\n';
	for(int i=2;i<n;i+=2)
		cout<<1<<' '<<i<<'\n'<<i<<' '<<i+1<<'\n'<<1<<' '<<i+n+1<<'\n'<<i+n+1<<' '<<i+n<<'\n';
	if(n%2==0)
		cout<<s<<' '<<n<<'\n'<<((s^n)^1)+n<<' '<<2*n;
	return 0;
}