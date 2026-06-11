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


long long N, K;
long long P[200002] = {0};
long double E[200002] = {0.0};
long double S[200002] = {0.0};

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for(int i=1; i<=N; i++){
		cin >> P[i];
	}

	for(int i=1; i<=N; i++){
		long long tmp = 0;
		for(int j=1; j<=P[i]; j++){
			tmp += j;
		}
		long double exp = (long double)tmp / (long double)P[i];
		E[i] = exp;
		if(i == 1){
			S[i] = exp;
		}
		else{
			S[i] = S[i-1] + exp;
		}
	}
	long double ans = 0.0;

	for(int i=1; i<=N-K+1; i++){
		long double tmp = S[i+K-1] - S[i-1];
		if(tmp > ans) ans = tmp;
	}

	printf("%.9Lf\n", ans);
	return 0;
}