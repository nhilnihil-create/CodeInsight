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
	int maxx = 0;
	int sum = 0;
	vector<ll> h(n);
	for (int i = 0;i < n;i++) {
		cin >> h[i];
	}
	for (int i = 1;i < n;i++) {
		if (h[i - 1] >=h[i]) {
			sum++;
			if (i != n - 1)
				continue;
		}
		maxx = max(maxx, sum);
		sum = 0;
	}
	cout << maxx;
}

