#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) (n); i++)
#define ll long long
#define scout cout << fixed << setprecision(10)
ll INF = 9e17;
ll mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	vector<long double> a(n);
	rep(i,n) cin >> a[i];
	long double ans = 0;
	rep(i,n) ans += 1/a[i];
	scout << 1/ans << endl;
}