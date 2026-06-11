#include<iostream>
#include<math.h>
#include<algorithm>
#define LL long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(0)
using namespace std;

bool isPrime(int x)
{
	for(int i=2; i*i<=x; i++) if(x%i==0) return false;
	return true;
}

int main()
{
	int x, i; cin>>x;
	if(x==2) { cout<<2<<endl; return 0; }
	
	for(i=x; ; i++)
	{
		if(isPrime(i)) break;
	}
	cout<<i<<endl;
}