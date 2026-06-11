#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

long long N, M;
string S;

static long long P = 1000000000LL + 7;

// base**kのmodを求める
LL modpow(LL base, LL k, LL mod){
	if(k == 0){ return 1; }
	if(k == 1){ return (base % mod); }
	if(k == 2){ return ((base*base) % mod); }

	LL q = k / 2;
	LL r = k % 2;
	// k = q*2 + r
	LL u = modpow((base*base)%mod, q, mod);
	LL v = modpow(base, r, mod);

	return ( (u * v ) % mod );
}

//dp[i][j]は、Sの末尾i+1桁を13で割ったあまりがjになる数の個数(modP)
long long dp[100000+2][13] = {0};

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	long long N = S.size();

	//まず末尾から
	char tmp[2] = {0};
	int c = 0;
	if(S[N-1] == '?'){
		for(int j=0; j<10; j++){
			dp[0][j] = 1;
		}
	}
	else{
		tmp[0] = S[N-1];
		c = atoi(tmp);
		dp[0][c] = 1;
	}

	for(int i = 1; i < N; i++){
		int j = N - 1 - i;
		LL e = modpow(10, i, 13);
		if(S[j] == '?'){
			for(c = 0; c < 10; c++){
				int r = (e * c) % 13;
				for(int k = 0; k < 13; k++){
					dp[i][(r+k)%13] += (dp[i-1][k] % P);
					dp[i][(r+k)%13] %= P;
				}
			}
		}
		else{
			tmp[0] = S[j];
			c = atoi(tmp);
			int r = (e * c) % 13;
			for(int k = 0; k < 13; k++){
				dp[i][(r + k)%13] = dp[i-1][k] % P;
			}
		}
	}
	long long ans = dp[N-1][5];
	printf("%lld\n", ans);
	return 0;
}