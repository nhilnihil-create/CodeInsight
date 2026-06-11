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

int L[2010];
bool judge(int x, int y, int z) {
	if (x < y + z && y < x + z && z < x + y) return true;
	else return false;
}
int main() 
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	sort(L, L + N);
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int ok = j;
			int ng = N;
			while (abs(ok - ng) > 1) {
				int mid = (ok + ng) / 2;
				if (judge(L[i], L[j], L[mid])) ok = mid;
				else ng = mid;
			}
			ans += ok - j;
		}
	}
	cout << ans << endl;
}
