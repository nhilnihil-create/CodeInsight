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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	long long H[100002] = {0};

	cin >> N;
	for(int i=1; i<=N; i++){ cin >> H[i]; }

	for(int i=N-1; i>=1; i--){
		long long a = H[i];
		long long b = H[i+1];
		if(a - b >= 2){
			printf("No\n");
			return 0;
		}
		else if(a - b == 1){
			H[i]--;
		}
	}
	printf("Yes\n");
	return 0;
}