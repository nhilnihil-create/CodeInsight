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
vector<long long> L;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		long long tmp;
		cin >> tmp;
		L.push_back(tmp);
	}
	sort(L.begin(), L.end());

	long long ans = 0;
	for(int i = 0; i < N - 2; i++){
		for(int j = i + 1; j < N - 1; j++){
			for(int k = j + 1; L[k] < L[i] + L[j]; k++){
				if( L[j] < L[k] + L[i]){
					ans++;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}