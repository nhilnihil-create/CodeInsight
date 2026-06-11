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
vector<long long> A, B;
map<long long, vector<int>> MB;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		long long a, b;
		cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
		MB[b].push_back(i);
	}
	sort(B.begin(), B.end());

	long long e = 0;
	int ng = 0;
	for(int i=0; i<B.size(); i++){
		if(i > 0 && B[i] == B[i-1]) continue;
		vector<int> &v = MB[B[i]];
		for(int j=0; j<v.size(); j++){
			e += A[v[j]];
			if(e > B[i]){
				ng = 1;
				break;
			}
		}
		if(ng == 1){
			break;
		}
	}
	if(ng == 1){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}