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
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<int> b(n);
	rep(i, n-1)
	{
		b[i] = a[i + 1] - a[i];
	}
	b[n - 1] = a[0] + k - a[n - 1];
	int m;
	 m= std::max_element(b.begin(), b.end()) - b.begin();
	int ma= *std::max_element(b.begin(), b.end());

	cout << k - ma << "\n";
	return 0;
}