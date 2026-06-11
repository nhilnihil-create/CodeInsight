#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	
	int s = 0;
	while(s<a)
	{
		s += n;
	}
	if(s <= b) cout << "OK";
	else cout << "NG";
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
