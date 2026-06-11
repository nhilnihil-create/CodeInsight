#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int h;
	cin>>h;
	int bit=0;
	unsigned long long int ans=0;
	unsigned long long int i=1;
	while(h>=1)
	{
		h=h/2;
		ans+=i;
		i=i*2;
	}
	cout<<ans;
}