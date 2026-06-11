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

long long N, M;
vector<long long> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	long long tot = 0;
	for(int i=0; i<M; i++){
		long long a;
		cin >> a;
		A.push_back(a);
		tot += a;
	}
	if(tot > N){
		printf("-1\n");
	}
	else{
		printf("%lld\n", N - tot);
	}
	return 0;
}