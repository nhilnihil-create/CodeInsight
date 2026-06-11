#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int m=1;
	while (m<n)
	{
		m*=2;
	}
	if (m==n)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n1 2\n2 3\n3 "<<1+n<<endl<<1+n<<" "<<2+n<<endl<<2+n<<" "<<3+n<<endl;
	int now=4;
	while (now<n)
	{
		cout<<now<<" "<<now+1<<endl<<now+1<<" "<<1+n<<endl<<1+n<<" "<<now+n<<endl<<now+n<<" "<<now+n+1<<endl;
		now+=2;
	}
	if (n%2==0)
	{
		cout<<n<<" "<<m/2+n<<endl<<n-m/2+1<<" "<<n+n<<endl;
	}
	return 0;
}
