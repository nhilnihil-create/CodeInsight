#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	ll a,b,k;
	cin >> a >> b >> k;
	ll x = max(0LL,a-k);
	ll y = max(0LL,b+a-k);
	y = min(y,b);
	cout << x << ' ' << y << endl;
	return 0;
}

