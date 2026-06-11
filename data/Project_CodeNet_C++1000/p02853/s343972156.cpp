#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int money(int n) {
	if (n==1) return 3;
	else if (n==2) return 2;
	else if (n==3) return 1;
	else  return 0;
}

int main() {
	int x,y;
	cin>>x>>y;
	int ans = 0;
	ans += money(x);
	ans += money(y);
	if (x==1&&y==1) ans += 4;
	ans *= 100000;
	cout << ans << endl;
	return 0;
}