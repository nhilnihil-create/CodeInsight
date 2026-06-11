#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define ll long long
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll int a,b,c,d,x,y,z,w,ans;
	cin >> a >> b >> c >> d;
	x=a*c;
	y=a*d;
	z=b*c;
	w=b*d;
	ans=max(x,w);
	ans=max(ans,y);
	ans=max(ans,z);
	
	cout << ans << endl;
	
	return 0;
}