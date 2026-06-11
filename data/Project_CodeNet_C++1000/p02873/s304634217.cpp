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
long long INF = (1LL<<62);
typedef long long LL;

LL a[500002] = {0};
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	LL N = S.size() + 1;
	for(int i=0; i<N; i++){
		a[i] = -1;
	}

	vector<LL> V;
	V.push_back(0);
	for(int i=0; i<N-1; i++){
		if(i+1 < N-1 && S[i] == '>' && S[i+1] == '<'){
			a[i+1] = 0;
			V.push_back((-1)*(i+1));
		}
		if(i+1 < N-1 && S[i] == '<' && S[i+1] == '>'){
			a[i+1] = INF;
			V.push_back(i+1);
		}
	}

	LL ans = 0;
	if(V.size() == 1){
		ans = (N*(N-1))/2 ;
		printf("%lld\n", ans);
		return 0;
	}

	V.push_back(N);
	for(int i=1; i<V.size(); i++){
		LL p = V[i-1];
		LL q = V[i];
		if(q < 0){
			for(int i=p+1; i<(-1)*q; i++){
				a[i] = abs(q) - i;
			}
		}
		else if(q > 0 && q != N){
			for(int i=(-1)*p+1; i<q; i++){
				a[i] = i - abs(p);
			}
		}
		else if(q == N){
			if(p < 0){
				for(int i=(-1)*p+1; i<q; i++){
					a[i] = i - abs(p);
				}
			}
			else if(p > 0){
				for(int i=p+1; i<q; i++){
					a[i] = abs(q) - i - 1;
				}
			}
		}
	}
	//a[0]を決定する
	LL c = V[1];
	for(int i=0; i<abs(c); i++){
		if(c < 0){
			a[i] = abs(c) - i;
		}
		else{
			a[i] = i;
		}
	}

	for(int i=0; i<N; i++){
		if(a[i] == INF){
			a[i] = max(a[i-1], a[i+1]) + 1;
		}
	}

	ans = 0;
	for(int i=0; i<N; i++){
		ans += a[i];
	}
	printf("%lld\n", ans);
	return 0;
}