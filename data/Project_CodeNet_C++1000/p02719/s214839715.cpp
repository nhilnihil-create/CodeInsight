#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k,x,y,ans;
	cin >> n >> k;
	x=k-n%k;
	y=n%k;
	ans=min(x,y);
	cout << ans << endl;
	return 0;
}