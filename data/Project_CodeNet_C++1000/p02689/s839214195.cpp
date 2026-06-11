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


int main()
{
	int n, m;
	cin >> n >> m;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];
	vector<bool> aa(n);
	rep(i, n) aa[i] = true;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		if (h[a - 1] < h[b - 1])
			aa[a - 1] = false;
		else if(h[a-1]>h[b-1])
			aa[b-1] = false;
		else {
			aa[a - 1] = false;
			aa[b - 1] = false;
		}
	}
	int ans = 0;
	rep(i, n) {
		if (aa[i]) ans++;
	}
	cout << ans;

}