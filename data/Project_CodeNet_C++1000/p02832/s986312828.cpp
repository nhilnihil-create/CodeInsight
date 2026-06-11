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

long long N;
vector<int> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=1; i<=N; i++){
		long long a;
		cin >> a;
		A.push_back(a);
	}
	long long ans = 0, v = 1, c = 0;
	int lastfound = 0;
	for(int i=0; i<A.size(); i++){
		c++;
		if(A[i] == v){
			lastfound = i + 1;
			ans += (c - 1);
			v++;
			c = 0;
		}
	}
	if(lastfound == 0){
		printf("-1\n");
		return 0;
	}
	if(lastfound != N){
		ans += (N - lastfound);
	}
	printf("%lld\n", ans);
	return 0;
}