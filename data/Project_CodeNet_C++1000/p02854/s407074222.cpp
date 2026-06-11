#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
char map[505][505];
int def[505][505];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int>to[200005];
ll a[200005];

int main() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll x = 0;
	ll ans;
	ll price = sum;
	for (int i = n - 1; i > 0; i--) {
		x += a[i];
		ans = sum - x;
		price = min(abs(ans-x),price);
	}
	cout << price << endl;
	return 0;
}