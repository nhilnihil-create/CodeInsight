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
	int n;
	cin >> n;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	int sum, ans, p;
	sum = 0;
	p = 0;
	for(int i = 0; i < n ;i++)
	{
		sum += d[i];
		p += d[i] * d[i];
	}
	ans = (sum * sum - p) / 2;
	cout << ans << "\n";
	return 0;
}