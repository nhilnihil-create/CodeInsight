#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int m,d;
	cin>>m>>d;
	int ans=0;
	for (int i = 1; i <= d; ++i)
	{
		int d1=i%10,d2=i/10;
		if (d1>=2&&d2>=2&&d1*d2<=m)
		{
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
