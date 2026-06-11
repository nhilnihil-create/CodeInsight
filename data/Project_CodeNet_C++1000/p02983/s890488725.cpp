#include <bits/stdc++.h>
using namespace std;

int main() {
	int l,r,k=0;
	cin >> l >> r;
	int l2=l%2019,r2=r%2019;
	if(r-l>=2019)
	{
		k=0;
	}
	else if(r2<l2)
	{
		k=0;
	}
	else
	{
		k=2018;
		for(int i=l2;i<r2;i++)
		{
			for(int j=i+1;j<=r2;j++)
			{
				k=min(k,(i*j)%2019);
			}
		}
	}
  cout << k << endl;
}
