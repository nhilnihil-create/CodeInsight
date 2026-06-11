#include <iostream>
using namespace std;
#define ll long long int 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	

	ll n;
	cin>>n;
	
	ll ans=0;
	for(int i=2;i<=10000010;i++)
	{
		if(n%i==0)
		{
			
			ll num=0;
			while(n%i==0)
			{
				n/=i;
				num++;
			}	

			for(int j=1;j< 10000;j++)
			{
				if(num<j)
					break;
				num-=j;
				ans++;
			}
		}
	}
	if(n!=1)
		ans++;
	cout<<ans;

	
	 

	return 0;
	
}