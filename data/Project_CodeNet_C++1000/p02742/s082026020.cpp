#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main () {
	ll H, W; cin >> H >> W;
	ll tmp = H * W;
	if (H == 1 || W == 1) {
		cout << "1" << endl;
	} else if (tmp % 2 == 0) {
		cout << tmp / 2 << endl;
	} else {
		cout << tmp / 2 + 1 << endl;
	}
}