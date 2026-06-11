#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	b = a;
	sort(b.rbegin(), b.rend());
	rep(i, n) {
		if (a[i] == b[0]) cout << b[1] << endl;
		else cout << b[0] << endl;
	}
}
