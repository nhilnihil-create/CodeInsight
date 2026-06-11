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
#define pf(n) printf("%lld\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	string s;
	cin >> s;

	if (s == "Sunny") {
		cout << "Cloudy\n";
	}
	else if (s == "Cloudy") {
		cout << "Rainy\n";
	}
	else {
		cout << "Sunny\n";
	}


	return 0;
}