#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include <algorithm>
#include<functional>
#include<cstdlib>
#include<cmath>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;

typedef pair<int, int> P;
typedef pair<long, long> LP;
typedef pair<int, P> PP;
typedef pair<long, LP> LPP;



int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };


int dp[1000010] = { 0 };
int dpodd[1000010] = { 0 };


int N = 0;
int C[191];
int Codd[51];

void input(void) {
	CI N;

	return;
}


int main(void) {
	int C_N;
	for (int i = 1; i <= 190;i++) {
		C[i - 1] = i * (i + 1) * (i + 2) / 6;
	}
	int ii = 1, jj = 0;
	while (true) {
		if (ii * (ii + 1) * (ii + 2) / 6 > 1000000) {
			break;
		}
		if ((ii * (ii + 1) * (ii + 2) / 6) % 2 == 1) {
			Codd[jj] = ii * (ii + 1) * (ii + 2) / 6;
			jj++;
		}
		ii++;
	}

	for (int i = 1; i <= 1000009; i++) {
		dp[i] = 1001000;
	}
	for (int i = 1; i <= 1000009; i++) {
		dpodd[i] = 1001000;
	}

	for (int j = 1; j <= 189; j++) {
		for (int i = 1; i <= 1000002; i++) {
			if (i < C[j - 1]) {
				dp[i] = dp[i];
			}
			else {
				dp[i] = min(dp[i], dp[i - C[j - 1]] + 1);
			}
		}

	}

	for (int j = 1; j <= 50; j++) {
		for (int i = 1; i <= 1000002; i++) {
			if (i < Codd[j - 1]) {
				dpodd[i] = dpodd[i];
			}
			else {
				dpodd[i] = min(dpodd[i], dpodd[i - Codd[j - 1]] + 1);
			}
		}
	}

	while (true) {
		input();
		if (N == 0) {
			break;
		}
		/*for (int i = 0; i < 190; i++) {
			if (C[i] > N) {
				C_N = i;
				break;
			}
		}*/
	

		

		CO dp[N] << " ";

		
		/*for (int i = 0; i < 50; i++) {
			if (Codd[i] > N) {
				C_N = i;
				break;
			}
		}*/
		

		CO dpodd[N] E
		
		
	}
	
	
	return 0;
}