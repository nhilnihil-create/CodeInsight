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
	int n;
	cin >> n;
	vector<int> a(n - 1);
	rep(i, n-1) cin >> a[i];

	map<int, int> b;
	rep(i, n - 1) {
		a[i]--;
		b[a[i]]++;
	}
	rep(i, n) {
		pf(b[i]);
	}

	return 0;
}