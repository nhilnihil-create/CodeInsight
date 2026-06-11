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
using namespace std;
ll M = 1000000000000000;


int main()
{
	int n;
	cin >> n;
	vector<int> hei(n);
	bool ok = true;
	for (int i = 0;i < n;i++) {
		cin >> hei[i];
		if (i > 0) {
			if (hei[i] - 1 >= hei[i - 1])
				hei[i]--;
		}
	}
	for (int i = 0;i < n-1;i++) {
		if (hei[i] > hei[i + 1])
			ok = false;
	}
	if (ok)
		cout << "Yes";
	else
		cout << "No";
}
