#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int fact(int n) {
	if (n == 0) return 1;
	else return n*fact(n-1);
}

int main() {
	int n, x[10], y[10];
	cin >> n;
	rep(i,n) cin >> x[i] >> y[i];
	double ans = 0;
	vector<int> num(n);
	rep(i,n) num[i] = i;
	do
	{
		for (int i = 0; i < n-1; i++)
		{
			int a = num[i], b = num[i+1];
			int d = (x[b]-x[a])*(x[b]-x[a])+(y[b]-y[a])*(y[b]-y[a]);
			ans += pow(d, 0.5);
		}
		
	} while (next_permutation(num.begin(), num.end()));
	ans /= fact(n);
	cout << fixed << setprecision(10);
	cout << ans << endl;
	return 0;
}