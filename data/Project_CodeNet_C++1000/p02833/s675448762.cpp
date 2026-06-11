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


/*
 * 2*(5**n)の倍数で見る。
 */

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	cin >> N;

	if((N % 2) == 1){
		printf("0\n");
		return 0;
	}

	LL ans = 0;
	LL w = 2*5;
	while(true){
		LL q = N / w;
		if(q == 0){
			break;
		}
		ans += q;
		w *= 5;
	}
	printf("%lld\n", ans);
	return 0;
}