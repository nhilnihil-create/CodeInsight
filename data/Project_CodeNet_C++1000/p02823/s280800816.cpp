#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define d  double 
#define endl "\n"

const ll int MOD=1e9+7;

void solve()
{
	ll n,a,b,x,ans;
	cin >> n >> a >> b;
	if((a+b)%2==0)
		ans = (b-a)/2;
	else
		ans = min(a-1,n-b)+1+(b-a-1)/2;
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	solve();
	return 0;
}