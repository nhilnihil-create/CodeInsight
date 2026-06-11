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
	bool res = true;
	int pos = 2;
	int prime[100000] = {};
	prime[1] = 2;
	for(int i=3;i<=300000;i+=2){
		res = true;
		FOR(t, 2, sqrt(i)) {
			if (i%t == 0) {
				res = false;
				break;
			}
		}
		if (res) {
			prime[pos] = i;
			pos++;
		}
	}
	while (1) {
		int n;
		int first = 0;
		int last = 0;
		bool flag = true;

		cin >> n;
		if (n == 0) {
			break;
		}
		FOR(t, 1, pos - 1) {
			if (flag) {
				if (prime[t] >= n + 1) {
					first = t;
					flag = false;
				}
			}
			else {
				if (prime[t] > 2 * n) {
					last = t;
					break;
				}
			}
		}
		cout << last - first << endl;
	}
}
