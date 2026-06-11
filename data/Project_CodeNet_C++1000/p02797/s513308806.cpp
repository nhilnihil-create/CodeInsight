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

	LL N, K, S;
	cin >> N >> K >> S;

	if(S == 1){
		for(int i=0; i<N; i++){
			if(i<K){
				printf("1");
			}
			else{
				printf("2");
			}
			if(i!=N-1){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
		return 0;
	}
	if(K == N){
		for(int i=0; i<N; i++){
			printf("%lld", S);
			if(i!=N-1){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
		return 0;
	}
	if(K == 0){
		if(S == 2){
			for(int i=0; i<N; i++){
				printf("%lld", 3LL);
				if(i!=N-1){
					printf(" ");
				}
				else{
					printf("\n");
				}
			}
		}
		else{
			for(int i=0; i<N; i++){
				printf("%lld", S-1);
				if(i!=N-1){
					printf(" ");
				}
				else{
					printf("\n");
				}
			}
		}
		return 0;
	}

	for(int i=0; i<N; i++){
		if(i < K){
			if((i % 2) == 0){
				printf("1");
			}
			else{
				printf("%lld", S-1);
			}
		}
		if(i == K){
			printf("%lld", S);
		}
		if(i > K){
			printf("%lld", S-1);
		}
		if(i!=N-1){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
	return 0;
}

