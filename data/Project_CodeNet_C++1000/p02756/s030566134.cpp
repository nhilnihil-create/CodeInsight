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
	string S;
	int Q;
	cin >> S >> Q;
	bool turn = false;
	string fsum, esum;
	while (Q--) {
		int T;
		cin >> T;
		if (T == 1) turn = !turn;
		else {
			int f;
			char c;
			cin >> f >> c;
			if (f == 1) {
				if (turn) esum = esum + c;
				else fsum = c + fsum;
			}
			else {
				if (turn) fsum = c + fsum;
				else esum = esum + c;
			}
		}
	}
	string ans = fsum + S + esum;
	if (turn) reverse(ans.begin(), ans.end());
	cout << ans << endl;
}