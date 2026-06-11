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
	ll a, b;
	cin >> a >> b;

	if ((a + b) % 2 != 0) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << (a + b) / 2 << endl;
	}
	
	return 0;
}