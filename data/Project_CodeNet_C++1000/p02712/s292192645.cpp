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
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;

	long long ans = 0;
	for(int i=1; i<=N; i++){
		if((i % 3) != 0 && (i % 5) != 0){
			ans += i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}