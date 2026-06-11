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
	int x, n, sa;
	int ans;
	sa = 100;
	cin >> x >> n;
	vector<int> pp(n);
	rep(i, n) cin >> pp[i];
	rep(i, 102) {
		bool ok = true;
		for (int a = 0;a < n;a++) {
			if (i == pp[a]) {
				ok = false;
				break;
			}
		}
		if (ok == false) continue;
		if (sa > abs(x - i)) {
			sa = abs(x - i);
			ans = i;
		}
	}
	cout << ans;
}
