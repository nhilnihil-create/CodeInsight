#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	ull n, k;
	cin >> n >> k;
	ull ans = 0;
	while (n != 0)
	{
		n = (n - n % k) / k;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}