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
	n--;
	vint b(n);
	rep(i, n) {
		cin >> b[i];
	}
	int ans = b[0];
	for (int i = 1; i <n; i++) {
		ans += min(b[i-1], b[i]);
	}
	ans += b[n - 1];
	cout << ans << endl;
	return 0;
}
