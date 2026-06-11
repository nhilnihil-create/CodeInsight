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

long long N, X, Y;
long long D[2002] = {0};

long long dist(int i, int j){
	if(j <= i) return -1;
	long long d1 = abs(j - i);
	long long d2 = abs(X - i) + 1 + abs(j - Y);
	return min(d1, d2); 
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> X >> Y;

	for(int i=1; i<=N-1; i++){
		for(int j=i+1; j<=N; j++){
			long long d = dist(i, j);
			D[d]++;
		}
	}
	for(int i=1; i<N; i++){
		printf("%lld\n", D[i]);
	}
	return 0;
}