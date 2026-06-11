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
vector<long long> A, B;


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	B.assign(N+1, 0);
	A.push_back(0);
	for(int i=1; i<=N; i++){
		long long a;
		cin >> a;
		A.push_back(a);
	}
	for(int i = N; i>= N/2 + 1; i--){
		B[i] = A[i];
	}
	for(int i = N/2; i>=1; i--){
		long long sum = 0;
		for(int j= 2; (i * j) <= N; j++){
			sum += B[i*j];
		}
		B[i] = sum - A[i];
		B[i] %= 2;
		if(B[i] < 0) B[i] += 2;
	}
	long long sumA = 0, sumB = 0;
	for(int i=1; i<=N; i++){
		M += B[i];
	}
	if((M % 2) != A[1]){
		printf("-1\n");
	}
	else{
		printf("%lld\n", M);
		if(M > 0){
			int cont = 0;
			for(int i=1; i<=N; i++){
				if(B[i] != 0){
					if(cont == 0){
						printf("%d", i);
						cont = 1;
					}
					else{
						printf(" %d", i);
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}