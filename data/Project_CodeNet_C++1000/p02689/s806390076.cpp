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
	int n, m;
	cin >> n >> m;
	int ans = 0;
	vector<ll> h(n);
	vector<bool> once(n); //true
	rep(i, n) once[i] = true;
	rep(i, n) cin >> h[i];
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		if (h[a - 1] > h[b - 1]) {
			once[b - 1] = false;
		}
		else if (h[a - 1] < h[b - 1]) {
			once[a - 1] = false;
		}
		else {
			once[a - 1] = false;
			once[b - 1] = false;
		}
	}
	rep(i, n) {
		if (once[i])
			ans++;
	}

	cout << ans;
}

