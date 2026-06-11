#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<functional>
#include<string>
#include<vector>
#include<cstring>
#include<utility>
#include<set>
#include<map>

#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 2e9
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
const double PI = acos(-1);

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//	freopen("input.txt", "r", stdin);
	
	int N; cin >> N;
	ll ans = 0;
	int last;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (i == 1) last = a;
		else {
			if (last > a) ans += last - a;
			else last = a;
		}
	}
	cout << ans;

}
