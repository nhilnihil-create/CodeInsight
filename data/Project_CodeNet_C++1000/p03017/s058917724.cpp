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

typedef long long LL;
static LL INF = (1LL<<62);

int E[200002] = {0};
map<int, int> M;

int f(int s, int e, int pos){
	int c = 0, b = -1, ret = 0;
	if(s > e || E[s] == 1 || E[e] == 1){
		return 1;
	}
	if(s == e){
		return 0;
	}
	if(pos <= 0){
		for(auto itr = M.begin(); itr != M.end(); itr++){
			int k = itr->first;
			int v = itr->second;
			if(s <= k && k <= e -1){
				return 1;
			}
		}
		return 0;
	}
	if(pos >= 1){
		b = E[pos];
		E[pos] = 1;
	}
	for(int i=s; i<=e; i++){
		if(E[i] == 1){
			c++;
		}
		else{
			c = 0;
		}
		if(c >= 2){
			break;
		}
	}
	if(c >= 2){
		ret = 1;
	}
	else{
		ret = 0;
	}
	if(pos >= 1){
		E[pos] = b;
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, A, B, C ,D;
	string S;
	cin >> N >> A >> B >> C >> D;
	cin >> S;
	int p = 0, c = 0;
	for(int i=0; i<S.size(); i++){
		if(S[i] == '#'){
			E[i+1] = 1;
			if(c == 0){
				p = i+1;
			}
			c++;
		}
		else{
			if(c > 1){
				M[p] = 1;
			}
			c = 0;
		}
	}

	if(C < D){
		if(f(B, D, -1) == 1 || f(A, C, -1) == 1){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
		return 0;
	}

	if(f(B, D, -1) == 1){
		printf("No\n");
		return 0;
	}
	if(f(A, C, D) == 0){
		printf("Yes\n");
		return 0;
	}
	for(int k=0; k<=D-B; k++){
		if(B+k-1 < 1 || B+k+1 >= N){
			continue;
		}
		if(D-k-1 < 1 || D-k+1 >= N){
			continue;
		}
		if(E[B+k-1] != 0 || E[B+k] != 0 || E[B+k+1] != 0){
			continue;
		}
		if(f(B, B+k, -1) == 0 && f(B+k, D, -1) == 0 && f(A, C, B+k) == 0){
			printf("Yes\n");
			return 0;
		}
		if(E[D-k-1] != 0 || E[D-k] != 0 || E[D-k+1] != 0){
			continue;
		}
		if(f(D-k, D, -1) == 0 && f(B, D-k, -1) == 0 && f(A, C, D-k) == 0){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
