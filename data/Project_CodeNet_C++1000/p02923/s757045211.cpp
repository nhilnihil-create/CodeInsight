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
ll M = 1000000000000000;


using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> ss(n);
	int maax = 0;
	int ans = 0;
	int cnt = 0;
	int j = 0;
	vector<int> aa(n);
	for (int i = 0;i < n;i++) {
		cin >> ss[i];
		if (maax >= ss[i]) {
			cnt++;
			maax = ss[i];
		}
		else {
			maax = ss[i];
			ans = max(ans,cnt);
			cnt = 0;
		}
		ans = max(cnt, ans);
	}
	
	cout << ans;
}
