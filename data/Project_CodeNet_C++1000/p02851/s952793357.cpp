#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#define INF 1001001001001001001
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;


int main() {
	int n;
	long long int k;
	cin >> n >> k;
	vector<long long int>a(n + 1);
	a[0] = 0;
	long long int x;
	rep(i, 0, n) {
		cin >> x;
		a[i + 1] = (a[i] + x) % k;
	}
	long long int uns_i;
	rep(i, 0, n + 1) {
		uns_i = i % k;
		a[i] = (a[i] - uns_i + k) % k;
	}
	long long int ans = 0;
	map<int, int>m;
	rep(i, 0, n + 1) {
		if (i >= k) m[a[i - k]]--;
		ans += m[a[i]];
		m[a[i]]++;
	}
	cout << ans << endl;
}
