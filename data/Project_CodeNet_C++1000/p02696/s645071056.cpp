#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	ll a, b, n; 
	cin >> a >> b >> n;
	
	
	ll mx = (a * min(n, b-1))/b;
	cout << mx;
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

