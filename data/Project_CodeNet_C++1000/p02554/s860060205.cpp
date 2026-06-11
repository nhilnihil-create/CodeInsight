#include <iostream>
#include <algorithm>
using namespace std;
long long n , mod = 1e9+7;
long long sol()
{
	long long a=1 ,b=1 ,c=1 ,res = 0 ,t=0;
	while(t++<n)
	{
		a = (a*10)%mod; 
		b = (b*9)%mod; 
		c = (c*8)%mod;
	} 
	b = (b*2)%mod;
	res = (a-b+mod+c)%mod;
	return res;				
}

int main() 
{	
	cin >> n;
	cout<<sol()<<'\n';
}