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

	LL X;
	cin >> X;

	if(X < 100 || (X > 105 && X < 200)){
		printf("0\n");
		return 0;
	}

	LL Q = X / 100;
	LL R = X % 100;

	if(R == 0){
		printf("1\n");
		return 0;
	}

	LL q = R / 5;
	LL r = R % 5;

	if(q > Q){
		printf("0\n");
		return 0;
	}

	if(q == Q){
		if(r == 0){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
		return 0;
	}
	printf("1\n");
	return 0;
}