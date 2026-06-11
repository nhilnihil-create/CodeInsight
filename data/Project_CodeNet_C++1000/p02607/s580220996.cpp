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
	cin >> N;
	
	int ans = 0;
	for(int i=0; i<N; i++){
		int a;
		cin >> a;
		if((i % 2) == 0 && (a % 2) == 1){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}