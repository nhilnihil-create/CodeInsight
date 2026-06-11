#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repbit(bit,n) for (int bit = 0; bit < (1<<n); bit++)
using namespace std;
typedef long long ll;

const int INF = 1001001001;
//const ll INF = 1000000000000000000;

int main() {
	int x;
	cin >> x;

	int ans;
	ans = x/200;
	ans = 9 - (ans - 1);
	cout << ans;
	return 0;
}
