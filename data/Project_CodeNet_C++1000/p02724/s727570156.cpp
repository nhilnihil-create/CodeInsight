#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100;
const int INF = 1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L

int main() {
	int x; cin >> x;
	ll ans = 0;
	ans += (x / 500) * 1000;
	x = x % 500;
	ans += (x / 5) * 5;
	cout << ans << endl;
}