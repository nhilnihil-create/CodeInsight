#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void no() {cout << "No" << endl;}
void yes() {cout << "Yes" << endl;}

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll x = c - (a + b);
	if (x <= 0) no();
	else {
		if (4 * a * b < x * x) yes();
		else no(); 
	}
}

int main() {
	solve();
	return 0;
}