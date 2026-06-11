#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin>>n;

	long long ans=0;
	int i=0;
	while(n>0)
	{
		n=n/2;
		ans+=pow(2,i);
		i++;
	}
  
  cout<<ans;
	return 0;
}