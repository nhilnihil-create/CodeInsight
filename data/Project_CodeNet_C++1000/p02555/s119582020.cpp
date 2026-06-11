#include <iostream>
#include <algorithm>
using namespace std;
long long n , mod = 1e9+7 ,s[2001]={1};
void sol()
{
	for(int i=3 ;i<=n ;i++)
		for(int j=3 ;j<=i ;j++)
		{
			s[i] = (s[i]+s[i-j])%mod;
		}							
}
int main() 
{	
	while(cin>>n)
	{
		sol();
		cout<<s[n]<<'\n';
	}	
}