#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for (int i = 1; i <= n-1; ++i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			int a=2,ans=1;
			while ((i*2/a%2)+(j*2/a%2)!=1)
			{
				a*=2;
				++ans;
			}
			if (j==i+1)
			{
				cout<<ans;
			}
			else
			{
				cout<<" "<<ans;
			}
		}
		cout<<endl;
	}
	return 0;
}
