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


string S;
vector<long long> LR;

void solve(string &S, int s, int e, vector<long long> &ANS){
	int rl = s;
	rl = S.find("RL", s);
	for(int i=s; i<=rl; i++){
		if((rl - i) % 2 == 0){
			ANS[rl]++;
		}
		else{
			ANS[rl+1]++;
		}
	}
	for(int i=rl+1; i<=e; i++){
		if((i - rl - 1) %2 == 0){
			ANS[rl+1]++;
		}
		else{
			ANS[rl]++;
		}
	}
}

//LRで分離され、RLのどちらかに収束する。
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> S;
	long long N = S.size();
	vector<LL> ANS;
	ANS.assign(N, 0);

	for(int i=0; i<N-1; i++){
		if(S[i] == 'L' && S[i+1] == 'R'){
			LR.push_back(i);
		}
	}

	if(LR.size() > 0){
		for(int k=0; k<LR.size(); k++){
			int s, e;
			e = LR[k];
			if(k == 0){
				s = 0;
			}
			else{
				s = LR[k - 1] + 1;
			}
			solve(S, s, e, ANS);
		}
		//最後
		int l = LR.size() - 1;
		solve(S, LR[l] + 1, N-1, ANS);
	}
	else{
		solve(S, 0, N-1, ANS);
	}

	for(int i=0; i<N; i++){
		printf("%lld", ANS[i]);
		if(i < N - 1) printf(" ");
	}
	printf("\n");
	return 0;
}