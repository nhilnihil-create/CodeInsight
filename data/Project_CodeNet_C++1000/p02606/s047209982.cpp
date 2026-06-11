#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int l,r,d,i,cnt=0;
	cin >> l >> r >> d;
	for(i=l;i<=r;i++)
	{
		if(i>=l && i<=r && i%d==0) 
		{
			cnt++;
		}
	}
	cout << cnt << endl;

	
	return 0;
}