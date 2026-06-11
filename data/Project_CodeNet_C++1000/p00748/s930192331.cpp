//#include <bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>


#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;

int dp[1000001] = {};
int ki[1000001] = {};

int main(void) {
	int poll[181] = {};

	FOR(i, 1, 180) {
		poll[i] = i * (i + 1)*(i + 2);
		poll[i] /= 6;
		//cout << poll[i] << endl;
	}
	FOR(i, 2, 1000000) {
		dp[i] = INF;
		ki[i] = INF;
	}
	dp[1] = 1;
	ki[1] = 1;
	FOR(i, 1, 1000000) {
		FOR(j, 1, 180) {
			if (i - poll[j] > 0) {
				dp[i] = min(dp[i], dp[i - poll[j]] + 1);
			}
			else if (i == poll[j]) {
				dp[i] = 1;
			}
			else {
				break;
			}
			
		}
	}
	FOR(i, 1, 1000000) {
		for(int j=1;j<=180;j+=4) {
			if (i - poll[j] > 0) {
				ki[i] = min(ki[i], ki[i - poll[j]] + 1);
			}
			else if (i == poll[j]) {
				ki[i] = 1;
			}
			else {
				break;
			}

		}
	}
	/*FOR(i, 1, 1000000) {
		cout << i << " " << ki[i] << endl;
	}*/
	while (1) {
		int n;
		int first = 0;
		int second = 0;

		cin >> n;
		if (n == 0) {
			break;
		}
		cout << dp[n] << " " << ki[n] << endl;

	}

	return 0;
}
