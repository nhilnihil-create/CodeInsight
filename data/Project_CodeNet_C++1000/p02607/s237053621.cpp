#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i,s,cnt=0;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> s;
		if(i%2!=0 && s%2!=0) cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}