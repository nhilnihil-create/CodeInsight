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
	int N, K, R, S, P;
	string T;
	cin >> N >> K >> R >> S >> P >> T;
	int ans = 0;
	string L = "";
	for (int i = 0; i < N; i++) {
		if (i - K >= 0) {
			if (T[i] == 'r' && L[i - K] != 'p') {
				ans += P;
				L += 'p';
			}
			else if (T[i] == 's' && L[i - K] != 'r') {
				ans += R;
				L += 'r';
			}
			else if (T[i] == 'p' && L[i - K] != 's') {
				ans += S;
				L += 's';
			}
			else {
				L += '.';
			}
		}
		else {
			if (T[i] == 'r') {
				ans += P;
				L += 'p';
			}
			if (T[i] == 's') {
				ans += R;
				L += 'r';
			}
			if (T[i] == 'p') {
				ans += S;
				L += 's';
			}
		}
	}
	cout << ans << endl;
}
