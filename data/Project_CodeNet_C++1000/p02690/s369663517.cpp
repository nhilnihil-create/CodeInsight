#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	int n;
	cin >> n;
	
	for(ll a = -120; a<=120; a++)
	{
		for(ll b = -120; b<=120; b++)
		{
			ll A = a * a * a * a * a;
			ll B = b * b * b * b * b;
			if(A-B == n) 
			{
				cout << a << " " << b << "\n";
				return ;
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

