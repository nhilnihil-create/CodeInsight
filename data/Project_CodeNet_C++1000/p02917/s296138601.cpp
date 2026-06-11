#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
int main(){
	int n,ans=0;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n - 1; i++)cin >> b.at(i);
	ans = b.at(0);
	for (int i = 1; i < n; i++) {
		ans += min(b.at(i), b.at(i - 1));
	}
	cout << ans+b.at(n-2) << endl;
	return 0;
}