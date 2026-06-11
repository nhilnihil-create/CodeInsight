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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	bool exist = false;
	rep(i, n) {
		if (a[i] == 1) exist = true;
	}
	if (!exist) {
		cout << -1 << endl;
		return 0;
	}

	int cnt = 0;
	int num = 1;
	rep(i, n) {
		if (a[i] == num) {
			num++;
			continue;
		}
		cnt++;
	}
	pf(cnt);

	return 0;
}