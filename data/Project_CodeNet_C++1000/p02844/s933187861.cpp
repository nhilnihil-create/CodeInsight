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

	LL N;
	string S;

	cin >> N;
	cin >> S;
	int ans = 0;
	for(int i=0; i<=999; i++){
		int c = 0;
		char pin[4] = {0};
		sprintf(pin, "%03d", i);
		for(int j=0; j<S.size(); j++){
			if(S[j] == pin[c]){
				c++;
				if(c > 2){
					break;
				}
			}
		}
		if(c > 2){
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}