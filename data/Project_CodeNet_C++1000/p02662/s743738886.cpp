#include<bits/stdc++.h>
using namespace std;

long long N, S;
long long A[3005];

#define DIV 998244353
long long memo[3005][9005];


int main(){
	cin >> N >> S;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	memo[0][0] = 1;
	for(long long i = 0; i < N; i++) {
		for(long long j = 0; j < 3002; j++) {
			if(memo[i][j]) {
				memo[i+1][j] += 2*memo[i][j];
				memo[i+1][j] %= DIV;
				memo[i+1][j+A[i]] += memo[i][j];
				memo[i+1][j+A[i]] %= DIV;
			}
		}
	}

	cout << memo[N][S] << endl;
}
