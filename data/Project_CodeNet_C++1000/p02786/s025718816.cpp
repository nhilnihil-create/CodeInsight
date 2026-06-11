#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];


int main()
{
	ll h;
	cin >> h;
	ll i = 0;
	while (h != 1)
	{
		h /= 2;
		i += 1;
	}
	ll ans = pow(2, i+1) - 1;
	cout << ans << "\n";
	return 0;
}