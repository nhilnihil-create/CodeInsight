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

ll A[2010];
int main()
{
	ll N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> A[i];
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i] > A[j]) {
				if (i < j) {
					ans = (ans + (K * (K + 1) / 2)) % mod;
				}
				else {
					ans = (ans + (K * (K - 1) / 2)) % mod;
				}
			}
			
		}
	}
	cout << ans << endl;
}
