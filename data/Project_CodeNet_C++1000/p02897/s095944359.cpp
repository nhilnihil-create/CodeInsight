#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	float ans=0;
	float odd=0;
	float even=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			odd++;
		}
		else{
			even++;
		}
	}
	ans=odd/(odd+even);
	cout<<ans;
	return 0;
}