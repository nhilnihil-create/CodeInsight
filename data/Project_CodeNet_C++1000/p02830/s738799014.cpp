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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	string S, T, U;
	cin >> N;
	cin >> S >> T;

	for(int i=0; i<N; i++){
		U.push_back(S[i]);
		U.push_back(T[i]);
	}
	printf("%s\n", U.c_str());
	return 0;

}

