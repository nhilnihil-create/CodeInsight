#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;
	ll ju = pow(10, 9);
	ll x, y, s;
	cin >> s;
	y = (s + ju - 1)/ju;
	x = ju * y - s;
	cout << "0 0 " << y << " 1 " << x << " " << ju << endl;
}
