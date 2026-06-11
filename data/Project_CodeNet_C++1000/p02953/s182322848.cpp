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
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;


int main()
{
	int n;
	cin >> n;
	bool ok = true;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	if (n != 1)  {
		for (int i = 0;i < n - 1;i++) {
			int sa = h[i + 1] - h[i];
			if (sa > 0) h[i + 1]--;
		}

		rep(i, n-1) {
			if (h[i] > h[i + 1]) ok = false;
		}
	}
	if (ok) cout << "Yes";
	else cout << "No";
}