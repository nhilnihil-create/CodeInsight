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

ll A[200010];
ll cnt[200010];
int main()
{
	int N; cin >> N;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		ans += cnt[A[i]];
		cnt[A[i]]++;
	}
	for (int i = 0; i < N; i++) {
		cout << ans - cnt[A[i]] + 1 << endl;
	}
}