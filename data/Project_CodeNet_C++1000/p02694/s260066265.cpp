#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	ll x;
	cin >> x;

	ll cnt = 0;
	ll money = 100;
	bool ok = true;
	while (ok) {
		ll risi = money / 100;
		if (money + risi >= x) {
			ok = false;
		}
		money += risi;
		cnt++;
	}
	cout << cnt << endl;

	return 0;
}