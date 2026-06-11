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
	int N;
	cin >> N;
	ll ans = 0;
	map<string, int> mp;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		sort(S.begin(), S.end());
		ans += mp[S];
		mp[S]++;
	}
	cout << ans << endl;
}