#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,i,j,p;cin>>n;
	for (i=0;i<=20;i++) if ((1<<i)==n){puts("No");exit(0);}else if ((1<<i)<n) p=i;
	puts("Yes");
	if (n&1)
	{
		for (i=2;i<=n;i+=2)
		{
			cout<<i<<' '<<i+1<<endl;
			cout<<i+n<<' '<<i+n+1<<endl;
			cout<<1<<' '<<i+1<<endl;
			cout<<1<<' '<<i+n<<endl;
		}
		cout<<n+1<<' '<<n+3;
	}
	else
	{
		int a=(1<<p),b=n-a;
		for (i=2;i<n;i+=2) 
		{
			cout<<i<<' '<<i+1<<endl;
			cout<<i+n<<' '<<i+n+1<<endl;
			if (i!=a) cout<<1<<' '<<i+1<<endl,cout<<1<<' '<<i+n<<endl;
		}
		cout<<b<<' '<<a<<endl;
		cout<<b+n+1<<' '<<a+n+1<<endl;
		cout<<n<<' '<<a<<endl;
		cout<<n+n<<' '<<b<<endl;
		cout<<n+1<<' '<<b+n+1;
	}
}
//a+1 a b b+1 1 b+n b+n+1 a+n+1 a+n
//5 4 2 3 1 8 9 11 10