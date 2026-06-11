#include <bits/stdc++.h>

#define FOR(i, a, b) for(long long int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;



int main(void) {
	
	while (1) {
		string s;
		int count = 0;
		int now = 0;
		int pos = -1;
		int dp[100] = {};

		getline(cin, s);
		if (s[0] == '.') {
			break;
		}
		FOR(i, 0, s.size() - 1) {
			switch (s[i]) {
			case '(':
				dp[i] = 1;
				count++;
				break;
			case ')':
				dp[i] = -1;
				count++;
				break;
			case '[':
				dp[i] = 2;
				count++;
				break;
			case ']':
				dp[i] = -2;
				count++;
				break;
			}
		}

		while (1) {
			bool check = false;
			int now;
			int i = 0;
			int t = 1;
			while (i<=s.size()-2) {
				if (dp[i] ==1||dp[i]==2) {
					now = dp[i];
					break;
				}
				i++;
			}
			t = i + 1;
			while (t <= s.size() - 1) {
				if (dp[t] + now == 0) {
					dp[i] = dp[t] = 0;
					count -= 2;
					break;
				}
				else if (dp[t] == 1 || dp[t] == 2) {
					now = dp[t];
					i = t;
				}
				else if (dp[t] == -1 || dp[t] == -2) {
					t = s.size() - 1;
				}
				t++;
			}
			if (t == s.size()) {
				break;
			}
			
		}

		if (count == 0) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		
	}

}
