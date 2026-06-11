#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<utility>
#include<functional>
#include<cfenv>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define vint vector<int>
#define vvint vector<vint>
#define P pair<ll,ll>
#define INT_MAX 2147483647
#define MOD 998244353
#define PI 3.14159265358979323846
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;

#define MAX 1000000000000

int main(void) {
	int n; cin >> n;
	vint a(n + 1);
	vint b(n + 1);
	vint c(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		cin >> c[i];
	}


	int p = 100;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += b[a[i]];
		if (p + 1 == a[i]) {
			ans += c[p];
		}
		p = a[i];
	}
	cout << ans << endl;
	return 0;
}
