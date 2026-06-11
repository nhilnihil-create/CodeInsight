#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int N = 1e5+10;
ll a[N], x[N];
int main() {
	int n;
	cin >> n;
	//ll sum = 0;
	rep(i,n) {
		cin >> a[i+1];
		x[1] += a[i+1];
	}
	for (int i = 2; i <= n; i += 2)
	{
		x[1] -= 2*a[i];	
	}
	for (int i = 2; i <= n; i++)
	{
		x[i] = 2*a[i-1] - x[i-1];
	}
	rep(i,n) {
		cout << x[i+1] << ' ';
	}
	
	cout << endl;
	return 0;
}