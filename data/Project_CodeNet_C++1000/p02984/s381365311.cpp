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

long long N;
vector<long long> A, X;


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=1; i<=N; i++){
		long long a;
		cin >> a;
		A.push_back(a);
	}
	long long x0 = 0;
	for(int i=0; i<N; i++){
		if(i % 2 == 0){
			x0 += A[i];
		}
		else{
			x0 -= A[i];
		}
	}
	x0 /= 2;
	X.push_back(x0);
	printf("%lld", X[0]*2);
	long long x = X[0];
	for(int i=1; i<N; i++){
		x = A[i-1] - X[i-1];
		printf(" %lld", x*2);
		X.push_back(x);
	}
	printf("\n");
	return 0;
}