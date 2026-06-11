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
int Max = 10 + 1e8;
int main()
{ 
	int n;
	cin >> n;
	int ans = 0;
	int cnt = 0;
	rep(i, n) {
		int a; cin >> a;
		int t = cnt + 1;
		if (t != a)
			ans++;
		else
			cnt++;
	}
	if (cnt == 0)
		cout << -1;
	else
		cout << ans;
}

