#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	ll S;
	cin >> S;
	if (S == ll(1e18))
	{
		cout << "0 0 0 1000000000 1000000000 0" << endl;
		return 0;
	}
	ll H = 1000000000;
	ll W = S / H + ll(1);
	ll a = S % 1000000000;
	cout << "1 0 0 " << H << " " << W << " " << a << endl;
	return 0;
}