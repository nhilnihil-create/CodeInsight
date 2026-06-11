#include <iostream>
using namespace std;
int n ;
int m(int a)
{
	int res=0;
	while(a) res++ ,a/=10;
	return res;
}
int main() 
{	
	while(cin>>n)
	{
		int ans=0;
		for(int i=1 ;i<=n ;i++)		
			if(m(i)&1) ans++;
		cout<<ans<<'\n';
	}	
}