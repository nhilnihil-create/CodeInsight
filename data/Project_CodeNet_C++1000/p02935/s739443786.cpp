#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>

using ll = long long;
int M = 100100100;
using namespace std;
int main()
{

	int n;
	cin >> n;
	vector<double> v(n);
	for (int i = 0;i < n;i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	double ans = (v[0] + v[1]) / 2;
	v[0] = ans;
	v[1] = M;
	
	sort(v.begin(), v.end());
	if (n == 2) {
		cout << ans;
		return 0;
	}

	for (int i = 2;i < n;i++) {
		ans = (v[1] + v[0]) / 2;
		v[0] = ans;
		v[1] = M;
		sort(v.begin(), v.end());

	}
	cout << ans;
	
	
}
