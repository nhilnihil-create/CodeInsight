#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int  L, R;
	cin >> L >> R;
	if (R - L >= 2019) {
		cout << 0 << endl;
		return 0;
	}
	int ans = mod;
	L %= 2019; R %= 2019;
	if (L > R) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = L; i <= R; i++) {
		for (int j = i + 1; j <= R; j++) {
			ans = min(ans, i * j % 2019);
		}
	}
	cout << ans << endl;
}