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
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n - 1);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n - 1) cin >> c[i];
	int sum = 0;
	rep(i, n) sum += b[i];
	rep(i, n-1)
	{
		if (a[i]+1 == a[i + 1])
		{
			sum += c[a[i]-1];
		}
	}

	cout << sum << "\n";
	return 0;
}