#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L

int main() {
	ll X, K, D; cin >> X >> K >> D;
	X = abs(X);

	ll tmp1 = X % D;
	ll tmp2 = D - tmp1;
	ll tmp3 = min(tmp1, tmp2);

	if ((K > X/D) && (K - X/D) % 2 == 1) cout << tmp2 << endl;
	else if ((K > X/D) && (K - X/D) % 2 == 0) cout << tmp1 << endl;
	else if (K == X/D) cout << tmp1 << endl;
	else cout << X - K*D << endl;
}