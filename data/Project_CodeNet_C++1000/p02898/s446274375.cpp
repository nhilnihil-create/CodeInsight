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
const int MOD = 998244353;
const ll INF = 1000000000000000000;


int main()
{
	int N, K;
	cin >> N >> K;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		if (h >= K) ans++;
	}
	cout << ans << endl;
}